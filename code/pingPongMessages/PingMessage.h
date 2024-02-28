//
// Created by user on 28.02.24.
//

#ifndef ACTORSYSTEM_PINGMESSAGE_H
#define ACTORSYSTEM_PINGMESSAGE_H

#include <string>
#include "submodules/ActorSystemLibCpp/messageBox/MessageBox.h"

class PingMessage : public MessageBox{
public:
    explicit PingMessage(std::string payload) : payload(std::move(payload)){

    }

    std::string payload;
//    ~PingMessage();
//    PingMessage(const PingMessage &testMessage);
//    TestMessage(TestMessage &&testMessage);
};


#endif //ACTORSYSTEM_PINGMESSAGE_H
