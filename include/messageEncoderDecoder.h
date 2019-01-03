//
// Created by nadavsklar on 1/3/19.
//

#ifndef BGSCLIENT_MESSAGEENCODERDECODER_H
#define BGSCLIENT_MESSAGEENCODERDECODER_H

#include <boost/asio/ip/tcp.hpp>
#include <list>
#include <zconf.h>
#include <src/Messages/Message.cpp>

using boost::asio::ip::tcp;

class messageEncoderDecoder {

    private:
        const std::string encoding = "utf-8";
        short typeOfMessage;
        int bytesReaded;
        bool isReaded;
        std::vector<char> bytes;
        Message* currentMessage;

    public:
        messageEncoderDecoder();
        ~messageEncoderDecoder();
        Message* decodeNextByte(char nextByte);
        char* encode(std::string line);
        short bytesToShort(char* bytesArr);
        void shortToBytes(short num, char* bytesArr);
        void ackRead(char nextByte);
        void errorRead(char nextByte);
        void notificationRead(char nextByte);
};


#endif //BGSCLIENT_MESSAGEENCODERDECODER_H
