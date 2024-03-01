#include "code/code.h"
#include "submodules/ActorSystemLibCpp/ActorSystemLibCpp.h"

int main() {

    Logger::setLoggerProperties("/home/user/CLionProjects/ActorSystemCpp/logback.properties");
    ActorSystem system;

    auto fa = system.createActor<TestActor>("FirstActor",1,2.0);
    auto sa = system.createActor<TestActor>("SecondActor",8,3.2);
    auto ta = system.createActor<TestActor>("ThirdActor",8,3.2);

    std::string payload_1 = "Hello from FirstActor";

    MessageBox * testMessage_1 = new TestMessage(payload_1);

    std::list<std::string>receivers = {"SecondActor","ThirdActor"};

    fa->tell(receivers, testMessage_1);

    while(1){

    }
    return 0;
}
