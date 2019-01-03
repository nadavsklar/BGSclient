//
// Created by nadavsklar on 1/3/19.
//

#include <src/Messages/ACKOrError.cpp>

class Error : public ACKOrError {

    public:
        Error() : ACKOrError(11) { };

        std::string messageString() { return "Error " + typeOfMessage; }

        void setTypeOfMessage(short typeOfMessage) {
            ACKOrError::typeOfMessage = typeOfMessage;
        }
};