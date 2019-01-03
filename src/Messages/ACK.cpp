//
// Created by nadavsklar on 1/3/19.
//

#include <src/Messages/ACKOrError.cpp>

class ACK : public ACKOrError {

    public:
        ACK() : ACKOrError(10){};

        std::string messageString() { return "ACK " + typeOfMessage; }

    public:
        virtual void setTypeOfMessage(short typeOfMessage) {
            ACKOrError::typeOfMessage = typeOfMessage;
        }
};