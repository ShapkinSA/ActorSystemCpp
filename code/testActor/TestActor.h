//
// Created by user on 21.02.24.
//

#ifndef ACTORSYSTEM_TESTACTOR_H
#define ACTORSYSTEM_TESTACTOR_H


#include "submodules/ActorSystemLibCpp/ActorSystemLibCpp.h"
#include "code/testMessage/TestMessage.h"

class TestActor : public AbstractActor{

private:
    int varInt;
    double varDouble;

public:
    TestActor(const std::string &name, int varInt, double varDouble);
    void callback1(const std::string & sender, const TestMessage *mb);
};


#endif //ACTORSYSTEM_TESTACTOR_H
