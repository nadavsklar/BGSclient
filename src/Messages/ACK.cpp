//
// Created by nadavsklar on 1/3/19.
//

#include <include/Message.h>
using namespace std;

ACK::ACK() : ACKOrError(10){};

std::string ACK::messageString() { return "ACK " + to_string(typeOfMessage); }
