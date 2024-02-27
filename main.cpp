#include "code/code.h"
#include "code/testMessage/TestMessage.h"

int main() {

    Logger::setLoggerProperties("/home/user/CLionProjects/ActorSystemCpp/logback.properties");
    ActorSystem system;

    auto fa = system.createActor<TestActor>("FirstActor",1,2.0);
    auto sa = system.createActor<TestActor>("SecondActor",8,3.2);

    std::string payload_1 = "Hello from FirstActor";
    std::string payload_2 = "Hello from SecondActor";

    TestMessage * testMessage_1 = new TestMessage(payload_1);
    TestMessage * testMessage_2 = new TestMessage(payload_2);

    fa->tell<TestMessage>("SecondActor", testMessage_1);
    sa->tell<TestMessage>("FirstActor", testMessage_2);


    while(1){
//        std::cout<<testMessage_1->payload<<std::endl;
//        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
    return 0;
}
