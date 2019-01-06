//
// Created by nadavsklar on 1/3/19.
//

#include "../include/Message.h"
#include <vector>

using namespace std;

UserListACK::UserListACK() : ACK(), numOfUsers(-1), userNameList(), currentNumOfUsers(0) { typeOfMessage = 7; }

short UserListACK::getNumOfUsers() const { return numOfUsers; }

void UserListACK::setNumOfUsers(short numOfUsers) { UserListACK::numOfUsers = numOfUsers; }

const std::vector<std::string> &UserListACK::getUserNameList() const { return userNameList; }

void UserListACK::addUserNameList(const std::string &userName) { UserListACK::userNameList.push_back(userName); }

std::string UserListACK::messageString() { return "ACK 7 " + std::to_string(numOfUsers) + " " + getUsersString(); }

std::string UserListACK::getUsersString() {
    std::string result = "";
    for (int i = 0; i < (int)userNameList.size(); i++) {
        if (i == (int)userNameList.size() - 1)
            result += userNameList[i];
        else
            result += userNameList[i] + " ";
    }
    return result;
}

int UserListACK::getCurrentNumOfUsers() const { return currentNumOfUsers; }

void UserListACK::increaseCurrentNumOfUsers() { UserListACK::currentNumOfUsers++; }
