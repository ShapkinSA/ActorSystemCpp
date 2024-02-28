//
// Created by user on 28.02.24.
//

#ifndef ACTORSYSTEM_PINGPONGACTOR_H
#define ACTORSYSTEM_PINGPONGACTOR_H


#include "submodules/ActorSystemLibCpp/abstractActor/AbstractActor.h"
#include "code/pingPongMessages/PingMessage.h"
#include "code/pingPongMessages/PongMessage.h"

class PingPongActor : public AbstractActor{

private:

public:
    PingPongActor(const std::string &name);
    void receivePing(const std::string & sender, const PingMessage *mb);
    void receivePong(const std::string & sender, const PongMessage *mb);

};


#endif //ACTORSYSTEM_PINGPONGACTOR_H
