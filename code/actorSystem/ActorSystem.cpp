//
// Created by user on 20.02.24.
//

#include "ActorSystem.h"

std::map<std::string, AbstractActor*> &ActorSystem::getActors() {
    return actors;
}



void ActorSystem::popTask() {
//    std::lock_guard<std::mutex> lock(m_mutex);
    tasks.pop();
}

void ActorSystem::traceQueue() {
    std::thread t([this]() {
                      while(1){
                          if (!tasks.empty()) {
                              auto currentTask = tasks.front();
                              log_info("ActorSystem found task: sender: {}, receiver: {}, type: {}. size of tasks {}", currentTask->sender, currentTask->receiver, typeid(*currentTask->messageBox).name(), tasks.size());
                              if(actors.contains(currentTask->receiver)){
                                  actors[currentTask->receiver]->pushTask(currentTask);
                              }
                              popTask();
                          }
                          log_info("size of tasks {}", tasks.size());
                          std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                      }
                  }
    );
    t.detach();
}




//AbstractActor* ActorSystem<T>::createActor(const std::string &name) {
//    getActors()[name] = std::make_shared<AbstractActor>(name);
//    getActors()[name]->actorSystem = this;
//    return getActors()[name].get();
//}

ActorSystem::ActorSystem() {
    traceQueue();
}

void ActorSystem::pushTask(const std::shared_ptr<DataExchanger>&dataExchanger) {
    tasks.push(dataExchanger);
}



//template<typename T, std::enable_if<std::is_base_of<AbstractActor, T>::value>::type *, typename... Arguments>
//T *ActorSystem::createActor(const std::string &name, Arguments...args) {
//    T * t = new T(name);
//    t->actorSystem = this;
//    getActors()[name] = std::make_shared<AbstractActor>(t);
//    return t;
//}



//template<typename T, std::enable_if<std::is_base_of<AbstractActor, T>::value>::type *>
//template<typename T, typename std::enable_if<std::is_base_of<AbstractActor, T>::value>::type* = nullptr>
//T *ActorSystem::createActor(const std::string &name) {
//    T * t = new T(name);
//    t->actorSystem = this;
//    getActors()[name] = std::make_shared<AbstractActor>(t);
//    return t;
//}




//template<typename T, typename std::enable_if<std::is_base_of<AbstractActor, T>::value>::type* = nullptr>
//T *ActorSystem::createActor(const std::string &name) {
//    getActors()[name] = std::make_shared<AbstractActor>(name);
//    getActors()[name]->actorSystem = this;
//    return getActors()[name].get();
//}

