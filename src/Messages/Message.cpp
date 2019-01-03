//
// Created by nadavsklar on 1/3/19.
//

#include <string>

class Message {

    protected:
        short opcode_;
    private:
        bool isReaded;

    public:
        Message(short opcode) : opcode_(opcode), isReaded(false) {}

        short getOpcode_() const {
            return opcode_;
        }

        void setOpcode_(short opcode_) {
            Message::opcode_ = opcode_;
        }

        bool IsReaded() const {
            return isReaded;
        }

        void setIsReaded(bool isReaded) {
            Message::isReaded = isReaded;
        }

        virtual std::string messageString() { return ""; }

};