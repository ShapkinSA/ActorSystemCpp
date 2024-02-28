#include "code/code.h"
#include "submodules/ActorSystemLibCpp/ActorSystemLibCpp.h"

int main() {

    Logger::setLoggerProperties("/home/user/CLionProjects/ActorSystemCpp/logback.properties");
    ActorSystem system;

    auto fa = system.createActor<TestActor>("FirstActor",1,2.0);
    auto sa = system.createActor<TestActor>("SecondActor",8,3.2);

    std::string payload_1 = "Hello from FirstActor";
    std::string payload_2 = "Hello from SecondActor";

    MessageBox * testMessage_1 = new TestMessage(payload_1);
    MessageBox * testMessage_2 = new TestMessage(payload_2);

    fa->tell("SecondActor", testMessage_1);
    sa->tell("FirstActor", testMessage_2);

    while(1){

    }
    return 0;
}
