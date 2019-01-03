//
// Created by nadavsklar on 1/3/19.
//
#include <include/Message.h>
using namespace std;

ACKOrError::ACKOrError(short opcode) : Message(opcode), typeOfMessage(-1) {}

short ACKOrError::getTypeOfMessage()  { return typeOfMessage; }

std::string ACKOrError::messageString() { return ""; }

void ACKOrError::setTypeOfMessage(short typeOfMessage) { ACKOrError::typeOfMessage = typeOfMessage; }
