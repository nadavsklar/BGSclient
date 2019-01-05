//
// Created by nadavsklar on 1/3/19.
//

#include <string>
#include "../include/Message.h"
using namespace std;
Message::Message(short opcode) : opcode_(opcode), isReaded(false) {}

short Message::getOpcode_() const {
    return opcode_;
}

void Message::setOpcode_(short opcode_) {
    Message::opcode_ = opcode_;
}

bool Message::IsReaded() {
    return isReaded;
}

void Message::setIsReaded(bool isReaded) {
    Message::isReaded = isReaded;
}

std::string Message::messageString() { return ""; }

