//
// Created by nadavsklar on 1/3/19.
//

#include <messageEncoderDecoder.h>
#include <Messages/Message.cpp>
#include <Messages/Error.cpp>
#include <Messages/Notification.cpp>
#include <Messages/ACK.cpp>

messageEncoderDecoder::messageEncoderDecoder() : typeOfMessage(-1), bytesReaded(0), bytes(), isReaded(false), currentMessage(nullptr)  {}

Message* messageEncoderDecoder::decodeNextByte(char nextByte) {
    if (typeOfMessage == -1) {
        currentMessage = nullptr;
        bytesReaded++;
        bytes.push_back(nextByte);
        if (bytesReaded == 2) {
            char *bytesArr = new char[2];
            bytesArr[0] = bytes[0];
            bytesArr[1] = bytes[1];
            typeOfMessage = bytesToShort(bytesArr);
            bytes.clear();
            switch (typeOfMessage) {
                case 9:
                    currentMessage = new Notification();
                    break;
                case 10:
                    currentMessage = new ACK();
                    break;
                case 11:
                    currentMessage = new Error();
                    break;
                default:
                    break;
            }
        }
    } else {
        switch (typeOfMessage) {
            case 9:
                ackRead(nextByte);
                break;
            case 10:
                notificationRead(nextByte);
                break;
            case 11:
                errorRead(nextByte);
                break;
            default:
                break;
        }
    }
    if (isReaded) {
        bytesReaded = 0;
        typeOfMessage = -1;
        return currentMessage;
    }
    else
        return nullptr;

}

void messageEncoderDecoder::ackRead(char nextByte) {

}

void messageEncoderDecoder::notificationRead(char nextByte) {

}

void messageEncoderDecoder::errorRead(char nextByte) {
    if (bytes.size() < 2) {
        bytes.push_back(nextByte);
    }
    else {
        char *bytesArr = new char[2];
        bytesArr[0] = bytes[0];
        bytesArr[1] = bytes[1];
        short typeOfMessageReceived = bytesToShort(bytesArr);
        bytes.clear();
        currentMessage += typeOfMessageReceived;
        isReaded = true;
    }
}


char* messageEncoderDecoder::encode(std::string line) {

}

short messageEncoderDecoder::bytesToShort(char *bytesArr) {
    short result = (short)((bytesArr[0] & 0xff) << 8);
    result += (short)(bytesArr[1] & 0xff);
    return result;
}

void messageEncoderDecoder::shortToBytes(short num, char *bytesArr) {
    bytesArr[0] = ((num >> 8) & 0xFF);
    bytesArr[1] = (num & 0xFF);
}