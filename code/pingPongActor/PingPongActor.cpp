//
// Created by user on 28.02.24.
//

#include "PingPongActor.h"


PingPongActor::PingPongActor(const std::string &name) : AbstractActor(name) {
    setCallback(PingMessage, receivePing);
    setCallback(PongMessage, receivePong);
}

void PingPongActor::receivePing(const std::string &sender, const PingMessage *mb) {
    log_info("({}) receive pingMessage from {}. Payload is {}", this->name, sender, mb->payload);
    MessageBox * pongMessage = new PongMessage("Pong from FirstActor");
    tell(sender, pongMessage);
}

void PingPongActor::receivePong(const std::string &sender, const PongMessage *mb) {
    log_info("({}) receive pongMessage from {}. Payload is {}", this->name, sender, mb->payload);
    MessageBox * pingMessage = new PingMessage("Ping from FirstActor");
    tell(this->name == "FirstActor" ? "SecondActor" : "FirstActor", pingMessage);
}
