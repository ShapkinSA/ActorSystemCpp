//
// Created by user on 28.02.24.
//

#ifndef ACTORSYSTEM_PONGMESSAGE_H
#define ACTORSYSTEM_PONGMESSAGE_H

class PongMessage :  public MessageBox{
public:
//    explicit PongMessage(std::string payload);

    explicit PongMessage(std::string payload) : payload(std::move(payload)){

    }

    std::string payload;
//    ~PongMessage();
//    PongMessage(const PongMessage &testMessage);
};

#endif //ACTORSYSTEM_PONGMESSAGE_H
