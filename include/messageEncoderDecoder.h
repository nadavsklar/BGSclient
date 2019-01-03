//
// Created by nadavsklar on 1/3/19.
//

#ifndef BGSCLIENT_MESSAGEENCODERDECODER_H
#define BGSCLIENT_MESSAGEENCODERDECODER_H

#include <boost/asio/ip/tcp.hpp>
#include <list>
#include <zconf.h>
#include <src/Messages/Message.cpp>
#include <src/Messages/ACK.cpp>
#include <src/Messages/Error.cpp>
#include <src/Messages/Notification.cpp>

using boost::asio::ip::tcp;

class messageEncoderDecoder {

    private:
        const std::string encoding = "utf-8";
        short typeOfMessage;
        int bytesReaded;
        bool isReaded;
        std::vector<char> bytes;
        Message* currentMessage;
        short bytesToShort(char* bytesArr);
        void shortToBytes(short num, char* bytesArr);
        void ackRead(char nextByte);
        void errorRead(char nextByte);
        void notificationRead(char nextByte);
        void followACKRead(char nextByte);
        void statRead(char nextByte);
        void userListRead(char nextByte);
        char* registerEncode(std::vector<char> bytesToencode, std::vector<std::string> tokens);
        char* loginEncode(std::vector<char> bytesToencode, std::vector<std::string> tokens);
        char* logoutEncode();
        char* followEncode(std::vector<char> bytesToencode, std::vector<std::string> tokens);
        char* postEncode(std::vector<char> bytesToencode, std::vector<std::string> tokens);
        char* pmEncode(std::vector<char> bytesToencode, std::vector<std::string> tokens);
        char* userListEncode();
        char* statEncode(std::vector<char> bytesToencode, std::vector<std::string> tokens);

    public:
        ~messageEncoderDecoder();
        messageEncoderDecoder();
        Message* decodeNextByte(char nextByte);
        char* encode(std::string line);
};


#endif //BGSCLIENT_MESSAGEENCODERDECODER_H
