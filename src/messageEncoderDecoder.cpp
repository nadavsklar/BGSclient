//
// Created by nadavsklar on 1/3/19.
//

#include <messageEncoderDecoder.h>
#include <Messages/Message.cpp>
#include <Messages/Error.cpp>
#include <Messages/Notification.cpp>
#include <Messages/ACK.cpp>
#include <Messages/FollowACK.cpp>
#include <Messages/StatACK.cpp>
#include <Messages/UserListACK.cpp>
#include <iostream>

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
                notificationRead(nextByte);
                break;
            case 10:
                ackRead(nextByte);
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
    ACK *tempMessage = ((ACK*)currentMessage);
    if (tempMessage->getTypeOfMessage() == -1) {
        if (bytes.size() < 2) {
            bytes.push_back(nextByte);
            if (bytes.size() == 2) {
                char * bytesArr = new char[bytes.size()];
                bytesArr[0] = bytes[0];
                bytesArr[1] = bytes[1];
                tempMessage->setTypeOfMessage(bytesToShort(bytesArr));
                bytes.clear();
                delete bytesArr;
            }
        }
    }
    else {
        switch (tempMessage->getTypeOfMessage()) {
            case 4:
                followACKRead(nextByte);
                break;
            case 7:
                userListRead(nextByte);
                break;
            case 8:
                statRead(nextByte);
                break;
            default:
                break;
        }
    }
}

void messageEncoderDecoder::followACKRead(char nextByte) {
    FollowACK *tempMessage = (FollowACK*)currentMessage;
    if (tempMessage->getNumOfUsers() == -1) {
        if (bytes.size() < 2) {
            bytes.push_back(nextByte);
            if (bytes.size() == 2) {
                char * bytesArr = new char[bytes.size()];
                bytesArr[0] = bytes[0];
                bytesArr[1] = bytes[1];
                tempMessage->setNumOfUsers(bytesToShort(bytesArr));
                bytes.clear();
                delete bytesArr;
            }
        }
    }
    else {
        if (tempMessage->getCurrentNumOfUsers() < tempMessage->getNumOfUsers()) {
            if (nextByte != '\0')
                bytes.push_back(nextByte);
            else {
                char *bytesArr = new char[bytes.size()];
                for (int i = 0; i < bytes.size(); i++)
                    bytesArr[i] = bytes[i];
                std::string currentUser(static_cast<const char*>(bytesArr), bytes.size());
                tempMessage->addUserNameList(currentUser);
                tempMessage->increaseCurrentNumOfUsers();
                bytes.clear();
                delete bytesArr;
            }
        }
        else
            tempMessage->setIsReaded(true);
    }
}

void messageEncoderDecoder::statRead(char nextByte) {
    StatACK *tempMessage = (StatACK*)currentMessage;
    if (tempMessage->getNumOfPosts() == -1) {
        if (bytes.size() < 2) {
            bytes.push_back(nextByte);
            if (bytes.size() == 2) {
                char * bytesArr = new char[bytes.size()];
                bytesArr[0] = bytes[0];
                bytesArr[1] = bytes[1];
                tempMessage->setNumOfPosts(bytesToShort(bytesArr));
                bytes.clear();
                delete bytesArr;
            }
        }
    }
    else {
        if (tempMessage->getNumOfFollowers() == -1) {
            if (bytes.size() < 2) {
                bytes.push_back(nextByte);
                if (bytes.size() == 2) {
                    char * bytesArr = new char[bytes.size()];
                    bytesArr[0] = bytes[0];
                    bytesArr[1] = bytes[1];
                    tempMessage->setNumOfFollowers(bytesToShort(bytesArr));
                    bytes.clear();
                    delete bytesArr;
                }
            }
        }
        else {
            if (tempMessage->getNumOfFollowing() == -1) {
                if (bytes.size() < 2) {
                    bytes.push_back(nextByte);
                    if (bytes.size() == 2) {
                        char * bytesArr = new char[bytes.size()];
                        bytesArr[0] = bytes[0];
                        bytesArr[1] = bytes[1];
                        tempMessage->setNumOfFollowing(bytesToShort(bytesArr));
                        tempMessage->setIsReaded(true);
                        bytes.clear();
                        delete bytesArr;
                    }
                }
            }
        }
    }
}

void messageEncoderDecoder::userListRead(char nextByte) {
    UserListACK *tempMessage = (UserListACK*)currentMessage;
    if (tempMessage->getNumOfUsers() == -1) {
        if (bytes.size() < 2) {
            bytes.push_back(nextByte);
            if (bytes.size() == 2) {
                char * bytesArr = new char[bytes.size()];
                bytesArr[0] = bytes[0];
                bytesArr[1] = bytes[1];
                tempMessage->setNumOfUsers(bytesToShort(bytesArr));
                bytes.clear();
                delete bytesArr;
            }
        }
    }
    else {
        if (tempMessage->getCurrentNumOfUsers() < tempMessage->getNumOfUsers()) {
            if (nextByte != '\0')
                bytes.push_back(nextByte);
            else {
                char *bytesArr = new char[bytes.size()];
                for (int i = 0; i < bytes.size(); i++)
                    bytesArr[i] = bytes[i];
                std::string currentUser(static_cast<const char*>(bytesArr), bytes.size());
                tempMessage->addUserNameList(currentUser);
                tempMessage->increaseCurrentNumOfUsers();
                bytes.clear();
                delete bytesArr;
            }
        }
        else
            tempMessage->setIsReaded(true);
    }
}

void messageEncoderDecoder::notificationRead(char nextByte) {
    Notification *tempMessage = ((Notification*)currentMessage);
    if (tempMessage->getPublicOrPrivate() == 'B')
        tempMessage->setPublicOrPrivate(nextByte);
    else {
        if (tempMessage->getPostingUser() == "") {
            if (nextByte != '\0')
                bytes.push_back(nextByte);
            else {
                char *bytesArr = new char[bytes.size()];
                for (int i = 0; i < bytes.size(); i++)
                    bytesArr[i] = bytes[i];
                std::string currentPostingUser(static_cast<const char*>(bytesArr), bytes.size());
                tempMessage->setPostingUser(currentPostingUser);
                bytes.clear();
                delete bytesArr;
            }
        }
        else {
            if (nextByte != '\0')
                bytes.push_back(nextByte);
            else {
                char *bytesArr = new char[bytes.size()];
                for (int i = 0; i < bytes.size(); i++)
                    bytesArr[i] = bytes[i];
                std::string currentContent(static_cast<const char*>(bytesArr), bytes.size());
                tempMessage->setContent(currentContent);
                bytes.clear();
                tempMessage->setIsReaded(true);
                delete bytesArr;
            }
        }
    }
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
        ((Error*)currentMessage)->setTypeOfMessage(typeOfMessageReceived);
        bytes.clear();
        isReaded = true;
        delete bytesArr;
    }
}


char* messageEncoderDecoder::encode(std::string line) {
    std::vector<char> bytesToencode;
    size_t pos = 0;
    std::vector<std::string> tokens;
    while ((pos = line.find(" ")) != std::string::npos) {
        tokens.push_back(line.substr(0, pos));
        line.erase(0, pos + 1);
    }
    if (tokens.size() == 0)
        return nullptr;
    if (tokens[0] == "REGISTER")
        return registerEncode(bytesToencode, tokens);
    if (tokens[0] == "LOGIN")
        return loginEncode(bytesToencode, tokens);
    if (tokens[0] == "LOGOUT")
        return logoutEncode();
    if (tokens[0] == "FOLLOW")
        return followEncode(bytesToencode, tokens);
    if (tokens[0] == "POST")
        return postEncode(bytesToencode, tokens);
    if (tokens[0] == "PM")
        return pmEncode(bytesToencode, tokens);
    if (tokens[0] == "USERLIST")
        return userListEncode();
    if (tokens[0] == "STAT")
        return statEncode(bytesToencode, tokens);
}

char* messageEncoderDecoder::registerEncode(std::vector<char> bytesToencode, std::vector<std::string> tokens) {
    char * opcode = new char[2];
    shortToBytes(1, opcode);
    bytesToencode.push_back(opcode[0]);
    bytesToencode.push_back(opcode[1]);
    std::vector<char> userName(tokens[1].begin(), tokens[1].end());
    userName.push_back('\0');
    for (int i = 0; i < userName.size(); i++)
        bytesToencode.push_back(userName[i]);
    std::vector<char> password(tokens[2].begin(), tokens[2].end());
    password.push_back('\0');
    for (int i = 0; i < password.size(); i++)
        bytesToencode.push_back(password[i]);

    char * toReturn = new char[bytesToencode.size()];
    for (int i = 0; i < bytesToencode.size(); i++)
        toReturn[i] = bytesToencode[i];
    return toReturn;
}

char* messageEncoderDecoder::loginEncode(std::vector<char> bytesToencode, std::vector<std::string> tokens) {
    char * opcode = new char[2];
    shortToBytes(2, opcode);
    bytesToencode.push_back(opcode[0]);
    bytesToencode.push_back(opcode[1]);
    std::vector<char> userName(tokens[1].begin(), tokens[1].end());
    userName.push_back('\0');
    for (int i = 0; i < userName.size(); i++)
        bytesToencode.push_back(userName[i]);
    std::vector<char> password(tokens[2].begin(), tokens[2].end());
    password.push_back('\0');
    for (int i = 0; i < password.size(); i++)
        bytesToencode.push_back(password[i]);

    char * toReturn = new char[bytesToencode.size()];
    for (int i = 0; i < bytesToencode.size(); i++)
        toReturn[i] = bytesToencode[i];
    return toReturn;
}

char* messageEncoderDecoder::logoutEncode() {
    char * opcode = new char[2];
    shortToBytes(3, opcode);
    return opcode;
}

char* messageEncoderDecoder::followEncode(std::vector<char> bytesToencode, std::vector<std::string> tokens) {
    char * opcode = new char[2];
    shortToBytes(4, opcode);
    bytesToencode.push_back(opcode[0]);
    bytesToencode.push_back(opcode[1]);
    bytesToencode.push_back(tokens[1][0]);
    shortToBytes(std::stoi(tokens[2]), opcode);
    bytesToencode.push_back(opcode[0]);
    bytesToencode.push_back(opcode[1]);
    for (int i = 3; i < tokens.size(); i++) {
        std::vector<char> currentUser(tokens[2].begin(), tokens[2].end());
        currentUser.push_back('\0');
        for (int j = 0; j < currentUser.size(); j++)
            bytesToencode.push_back(currentUser[j]);
    }
    char * toReturn = new char[bytesToencode.size()];
    for (int i = 0; i < bytesToencode.size(); i++)
        toReturn[i] = bytesToencode[i];
    return toReturn;
}

char* messageEncoderDecoder::postEncode(std::vector<char> bytesToencode, std::vector<std::string> tokens) {
    char * opcode = new char[2];
    shortToBytes(5, opcode);
    bytesToencode.push_back(opcode[0]);
    bytesToencode.push_back(opcode[1]);
    delete opcode;

    std::vector<char> content(tokens[1].begin(), tokens[1].end());
    for (int i = 0; i < content.size(); i++)
        bytesToencode.push_back(content[i]);
    content.push_back('\0');
    char * toReturn = new char[bytesToencode.size()];
    for (int i = 0; i < bytesToencode.size(); i++)
        toReturn[i] = bytesToencode[i];
    return toReturn;
}

char* messageEncoderDecoder::pmEncode(std::vector<char> bytesToencode, std::vector<std::string> tokens) {
    char *  opcode = new char[2];
    shortToBytes(6, opcode);
    bytesToencode.push_back(opcode[0]);
    bytesToencode.push_back(opcode[1]);
    delete opcode;

    std::vector<char> currentUser(tokens[1].begin(), tokens[1].end());
    for (int i = 0; i < currentUser.size(); i++)
        bytesToencode.push_back(currentUser[i]);
    currentUser.push_back('\0');

    std::vector<char> content(tokens[2].begin(), tokens[2].end());
    for (int i = 0; i < content.size(); i++)
        bytesToencode.push_back(content[i]);
    currentUser.push_back('\0');

    char * toReturn = new char[bytesToencode.size()];
    for (int i = 0; i < bytesToencode.size(); i++)
        toReturn[i] = bytesToencode[i];
    return toReturn;
}

char* messageEncoderDecoder::userListEncode() {
    char * opcode = new char[2];
    shortToBytes(7, opcode);
    return opcode;
}

char* messageEncoderDecoder::statEncode(std::vector<char> bytesToencode, std::vector<std::string> tokens) {
    char * opcode = new char[2];
    shortToBytes(8, opcode);
    bytesToencode.push_back(opcode[0]);
    bytesToencode.push_back(opcode[1]);
    delete opcode;

    std::vector<char> currentUser(tokens[1].begin(), tokens[1].end());
    for (int i = 0; i < currentUser.size(); i++)
        bytesToencode.push_back(currentUser[i]);
    currentUser.push_back('\0');

    char * toReturn = new char[bytesToencode.size()];
    for (int i = 0; i < bytesToencode.size(); i++)
        toReturn[i] = bytesToencode[i];
    return toReturn;
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
