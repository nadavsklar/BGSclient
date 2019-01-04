//
// Created by nadavsklar on 1/3/19.
//

#include <include/messageEncoderDecoder.h>
#include <iostream>
#include <thread>
#include <ReadTask.h>
#include <include/connectionHandler.h>
using namespace std;

ReadTask::ReadTask(ConnectionHandler& handler, bool& shouldTerminate, bool& failLogout) : handler(handler), shouldTerminate(shouldTerminate),
failLogout(failLogout){}

void ReadTask::run() {
    std::string answer;
    //From here we will see the rest of the ehco client implementation:
    while (!shouldTerminate) {
        if (!handler.getLine(answer)) {
            std::cout << "Disconnected. Exiting...\n" << std::endl;
            shouldTerminate = true;
        }
        if (answer == "ERROR 3")
            failLogout = true;
        if (answer == "ACK 3")
            shouldTerminate = true;
        std::cout << answer << std::endl;
        answer = "";

    }
}