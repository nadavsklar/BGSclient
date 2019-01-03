//
// Created by nadavsklar on 1/3/19.
//

#include <src/Messages/Message.cpp>

class ACKOrError : public Message {

    protected:
        short typeOfMessage;

    public:
        ACKOrError(short opcode) : Message(opcode), typeOfMessage(-1) {}

        short getTypeOfMessage()  {
            return typeOfMessage;
        }

        virtual std::string messageString() { return ""; }

    protected:
        virtual void setTypeOfMessage(short typeOfMessage) {
            ACKOrError::typeOfMessage = typeOfMessage;
        }
};