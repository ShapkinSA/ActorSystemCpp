//
// Created by user on 21.02.24.
//

#include "TestActor.h"


TestActor::TestActor(const std::string &name, int varInt, double varDouble) : AbstractActor(name), varInt(varInt),varDouble(varDouble) {
    setCallback(TestMessage, callback1);
}

void TestActor::callback1(const std::string & sender, const TestMessage *mb) {
    log_info("({}) receive testMessage from {}. Callback1. Payload is {}", this->name, sender, mb->payload);
}

void TestActor::preStart() {
    log_info("({}) prestart",this->name);
}