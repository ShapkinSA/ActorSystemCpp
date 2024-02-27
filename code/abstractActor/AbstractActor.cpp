//
// Created by user on 20.02.24.
//

#include "AbstractActor.h"
#include "code/testMessage/TestMessage.h"

#include <utility>

AbstractActor::AbstractActor(std::string name) : name(std::move(name)) {
    traceQueue();


}

void AbstractActor::traceQueue() {
    std::thread t([this]() {
                      while (1) {
                          if (!actorRequests.empty()) {
                              auto task = actorRequests.front();
                              log_info("I ({}) found actorRequest: sender: {}, receiver: {}, payload type: {}. size of actorRequests {}", this->name, task->sender, task->receiver, typeid(*task->messageBox).name(), actorRequests.size());
                              //handler
                              if(callbackMap.contains(typeid(*task->messageBox))){
                                  callbackMap[typeid(*task->messageBox)](task->sender, task->messageBox);
                              }
                              popTask();
                          }
                          log_info("({}) size of actorRequests {}", this->name, actorRequests.size());
                          std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                      }
                  }
    );
    t.detach();
}

void AbstractActor::pushTask(const std::shared_ptr<DataExchanger>&dataExchanger) {
    std::mutex m_mutex;
    std::lock_guard<std::mutex> lock(m_mutex);
    actorRequests.push(dataExchanger);
}

void AbstractActor::popTask() {
    std::mutex m_mutex;
    std::lock_guard<std::mutex> lock(m_mutex);
    actorRequests.pop();
}