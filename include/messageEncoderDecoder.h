//
// Created by nadavsklar on 1/3/19.
//

#ifndef BGSCLIENT_MESSAGEENCODERDECODER_H
#define BGSCLIENT_MESSAGEENCODERDECODER_H

#include <boost/asio/ip/tcp.hpp>
#include <list>
#include <zconf.h>

using boost::asio::ip::tcp;

class messageEncoderDecoder {

    private:
        const std::string encoding = "utf-8";
        short typeOfMessage;
        int bytesReaded;
        std::vector<char> bytes;
        std::string currentMessage;

    public:
        messageEncoderDecoder();
        ~messageEncoderDecoder();
        std::string decodeNextByte(char nextByte);
        char* encode(std::string line);
        short bytesToShort(char* bytesArr);
        void shortToBytes(short num, char* bytesArr);
        void ackRead(char nextByte);
        void errorRead(char nextByte);
        void notificationRead(char nextByte);
};


#endif //BGSCLIENT_MESSAGEENCODERDECODER_H
