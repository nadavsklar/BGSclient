//
// Created by nadavsklar on 1/3/19.
//

#ifndef BGSCLIENT_MESSAGEENCODERDECODER_H
#define BGSCLIENT_MESSAGEENCODERDECODER_H

#include <boost/asio/ip/tcp.hpp>
#include <list>
#include <zconf.h>
#include <Message.h>

using boost::asio::ip::tcp;
using namespace std;

class messageEncoderDecoder {

private:
    const std::string encoding = "utf-8";
    short typeOfMessage;
    int bytesReaded;
    std::vector<char> bytes;
    Message *currentMessage;

    short bytesToShort(char *bytesArr);
    void shortToBytes(short num, char *bytesArr);
    void ackRead(char nextByte);
    void errorRead(char nextByte);
    void notificationRead(char nextByte);
    void followACKRead(char nextByte);
    void statRead(char nextByte);
    void userListRead(char nextByte);
    std::vector<char> registerEncode(std::vector<char> bytesToencode, std::vector<std::string> tokens);
    std::vector<char> loginEncode(std::vector<char> bytesToencode, std::vector<std::string> tokens);
    std::vector<char> logoutEncode();
    std::vector<char> followEncode(std::vector<char> bytesToencode, std::vector<std::string> tokens);
    std::vector<char> postEncode(std::vector<char> bytesToencode, std::vector<std::string> tokens);
    std::vector<char> pmEncode(std::vector<char> bytesToencode, std::vector<std::string> tokens);
    std::vector<char> userListEncode();
    std::vector<char> statEncode(std::vector<char> bytesToencode, std::vector<std::string> tokens);


public:
    ~messageEncoderDecoder();
    messageEncoderDecoder();
    messageEncoderDecoder(const messageEncoderDecoder &other);
    messageEncoderDecoder& operator=(const messageEncoderDecoder &other);
    Message *decodeNextByte(char nextByte);
    std::vector<char> encode(std::string line);
};


#endif //BGSCLIENT_MESSAGEENCODERDECODER_H
