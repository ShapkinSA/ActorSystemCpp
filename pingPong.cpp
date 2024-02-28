#include "code/code.h"
#include "code/pingPongActor/PingPongActor.h"

int main() {

    Logger::setLoggerProperties("/home/user/CLionProjects/ActorSystemCpp/logback.properties");
    ActorSystem system;

    auto fa = system.createActor<PingPongActor>("FirstActor");
    auto sa = system.createActor<PingPongActor>("SecondActor");

    std::string payload_1 = "Ping from FirstActor";

    MessageBox * ping_message = new PingMessage(payload_1);

    fa->tell("SecondActor", ping_message);

    while(1){

    }
    return 0;
}
