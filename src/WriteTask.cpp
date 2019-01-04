//
// Created by nadavsklar on 1/3/19.
//

#include "WriteTask.h"
#include <include/messageEncoderDecoder.h>
#include <iostream>
#include <thread>
using namespace std;

WriteTask::WriteTask(ConnectionHandler& handler, bool& shouldTerminate, bool& failLogout): handler(handler),
shouldTerminate(shouldTerminate), failLogout(failLogout){ }

void WriteTask::run() {
    messageEncoderDecoder* med = new messageEncoderDecoder();
    //From here we will see the rest of the ehco client implementation:
    while (!shouldTerminate) {
        const short bufsize = 1024;
        char buf[bufsize];
        std::cin.getline(buf, bufsize);
        std::string line(buf);
        std::vector<char> bytesToSend = med->encode(line);
        if (!bytesToSend.empty()) {
            char bytesArr[bytesToSend.size()];
            for (int i = 0; i < bytesToSend.size(); i++)
                bytesArr[i] = bytesToSend[i];
            if (!handler.sendBytes(bytesArr, bytesToSend.size())) {
                std::cout << "Disconnected. Exiting...\n" << std::endl;
                shouldTerminate = true;
            }
            if (line == "LOGOUT") {
                while (1) {
                    if (shouldTerminate)
                        return;
                    else {
                        if (failLogout) {
                            failLogout = false;
                            break;
                        }
                    }
                }
            }
        }
    }
}

