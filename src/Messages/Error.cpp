//
// Created by nadavsklar on 1/3/19.
//

#include <include/Message.h>
using namespace std;

Error::Error() : ACKOrError(11) { };

std::string Error::messageString() { return "Error " + to_string(typeOfMessage); }
