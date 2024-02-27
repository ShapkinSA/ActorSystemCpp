//
// Created by user on 22.02.24.
//

#include "TestMessage.h"

#include <utility>
#include <iostream>

TestMessage::TestMessage(std::string payload) : payload(std::move(payload)) {
    std::cout<<"NEW TEST MESSAGE"<<std::endl;
}

TestMessage::TestMessage(const TestMessage &testMessage) {
    std::cout<<"COPY NEW TEST MESSAGE with content "<<testMessage.payload<<std::endl;
    this->payload = testMessage.payload;
}

TestMessage::~TestMessage() {
    std::cout<<"DELETE TestMessage with content "<<payload<<std::endl;
}

//TestMessage::TestMessage(TestMessage &&testMessage) {
//    int gf = 2;
//}
