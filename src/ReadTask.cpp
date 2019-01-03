//
// Created by nadavsklar on 1/3/19.
//

#include <include/messageEncoderDecoder.h>
#include <iostream>
#include <thread>
#include "ReadTask.h"

ReadTask::ReadTask(ConnectionHandler *handler): handler(handler) { }

void ReadTask::run() {
    messageEncoderDecoder * med = new messageEncoderDecoder();
    //From here we will see the rest of the ehco client implementation:
    while (1) {
        const short bufsize = 1024;
        char buf[bufsize];
        std::cin.getline(buf, bufsize);
        std::string line(buf);
        std::vector<char> bytesToSend = med->encode(line);
        char bytesArr[bytesToSend.size()];
        for (int i = 0; i < bytesToSend.size(); i++)
            bytesArr[i] = bytesToSend[i];
        if (!handler->sendBytes(bytesArr, bytesToSend.size())) {
            std::cout << "Disconnected. Exiting...\n" << std::endl;
            break;
        }
    }
}