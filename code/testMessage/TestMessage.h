//
// Created by user on 22.02.24.
//

#ifndef ACTORSYSTEM_TESTMESSAGE_H
#define ACTORSYSTEM_TESTMESSAGE_H


#include <string>
#include "code/messageBox/MessageBox.h"

class TestMessage :  public MessageBox{
public:
    explicit TestMessage(std::string payload);
    std::string payload;
    ~TestMessage();
    TestMessage(const TestMessage &testMessage);
};


#endif //ACTORSYSTEM_TESTMESSAGE_H
