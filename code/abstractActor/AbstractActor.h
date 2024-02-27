//
// Created by user on 20.02.24.
//

#ifndef ACTORSYSTEM_ABSTRACTACTOR_H
#define ACTORSYSTEM_ABSTRACTACTOR_H

#include <string>
#include "code/actorSystem/ActorSystem.h"
#include "code/utils/Logger.h"
#include <queue>
#include <functional>
#include <typeindex>
#include <any>
#include "code/dataExchanger/DataExchanger.h"

//#define setCallback(type,function) (callbackMap[type] = [this](const std::string & sender,  MessageBox *mb){function(sender,mb);})
#define setCallback(type,function) (callbackMap[typeid(type)] = [this](const std::string & sender,  MessageBox *mb){function(sender,mb);})

class ActorSystem;

template<class T, typename std::enable_if<std::is_base_of<MessageBox, T>::value>::type * = nullptr>
struct MapWrapper
{
    std::map<const std::type_index, std::function<void(const std::string &sender,  const T *messageBox)>> callbackMap;
};

class AbstractActor {
public:
    explicit AbstractActor(std::string name);
    virtual ~AbstractActor() = default;
//    void virtual setAllCallbacks() = 0;

public:
    ActorSystem *actorSystem;
    std::string name;
    std::queue<std::shared_ptr<DataExchanger>> actorRequests;

//    mutable std::mutex m_mutex;

    void pushTask(const std::shared_ptr<DataExchanger>&dataExchanger);
    void popTask();


    template<typename T, typename std::enable_if<std::is_base_of<MessageBox, T>::value>::type * = nullptr>
    void tell(const std::string &receiver, T &messageBox) {
        //work with copy
        T *copy = new T(messageBox);
        actorSystem->pushTask(std::make_shared<DataExchanger>(name, receiver, dynamic_cast<MessageBox*>(copy)));
    }



//    template<typename T, typename std::enable_if<std::is_base_of<MessageBox, T>::value>::type * = nullptr>
//    template< typename FuncType>
//    void setCallback(const std::type_index type, const std::type_index at, FuncType ft) {
//        callbackMap[type] = static_cast<std::function<void(const std::basic_string<char> &, MessageBox *)>>(std::bind(
//                &ft, at, std::placeholders::_1, std::placeholders::_2));
//    }

//    template<typename T_a, typename std::enable_if<std::is_base_of<AbstractActor, T_a>::value>::type * = nullptr>
//    void setCallback(const std::type_index type, std::function<void(T_a*)(const std::string &, MessageBox *)> f) {
//        callbackMap[type] = std::bind(f, this, std::placeholders::_1, std::placeholders::_2);
//    }


//    void setCallback(const std::type_index type, std::function<void(AbstractActor::*)(const std::string &, MessageBox *)> &f) {
////        callbackMap[type] = std::bind(f, this, std::placeholders::_1, std::placeholders::_2);
////        callbackMap.emplace(type,[this, f](auto & PH1, auto * PH2) { return f(this, std::forward<decltype(PH1)>(PH1), std::forward<decltype(PH2)>(PH2)); });
//        callbackMap.insert({
//                           type,
//                           [this, f](std::string str) { std::function<void(AbstractActor::*)(const std::string &, MessageBox *)}
//                   });
//    }

//    template<typename T_a, typename std::enable_if<std::is_base_of<AbstractActor, T_a>::value>::type * = nullptr, typename T_c, typename std::enable_if<std::is_base_of<MessageBox, T_c>::value>::type * = nullptr>
//    void setCallback(const std::type_index type, AbstractActor* a, std::function<void(T_a::*)(const std::string &, MessageBox *)> f) {
//        callbackMap[type] = std::bind(f, a, std::placeholders::_1, std::placeholders::_2);
//    }


    void setCallbacks(const std::type_index type, std::function<void(const std::string &, MessageBox *)> f) {
//        callbackMap[type] = std::bind(f, this, std::placeholders::_1, std::placeholders::_2);;
        callbackMap[type] = f;
    }




//    std::map<const std::type_index,  std::function<void(const std::string &, MessageBox *messageBox)>> callbackMap;
//    std::map<const std::type_index,  std::function<void(AbstractActor::*)(const std::string &, MessageBox *)>> callbackMap;
    std::map<const std::type_index,  std::function<void(const std::string &, MessageBox *)>> callbackMap;


//    virtual void setCallback(const std::type_index type, std::function<void(AbstractActor::*)(const std::string &, MessageBox *)> &f) {
//        callbackMap[type] = [this](auto && PH1, auto && PH2) { this->f(std::forward<decltype(PH1)>(PH1), std::forward<decltype(PH2)>(PH2)); };;
//
////        auto a = std::bind(&f, this, std::placeholders::_1, std::placeholders::_2);
////        callbackMap.emplace(type, std::bind(&f, this, std::placeholders::_1, std::placeholders::_2));
//    }


//    void setCallback(const std::type_index type, (void*)(const std::string &, MessageBox *) &f) {
//        callbackMap[type] = std::bind(f, this, std::placeholders::_1, std::placeholders::_2);
//    }



//    callbackMap[type] = static_cast<const std::function<void(const std::basic_string<char> &,
//                                                             MessageBox *)>>(std::bind(&f, this,
//    std::placeholders::_1,
//    std::placeholders::_2));

private:
    void traceQueue();
};


#endif //ACTORSYSTEM_ABSTRACTACTOR_H
