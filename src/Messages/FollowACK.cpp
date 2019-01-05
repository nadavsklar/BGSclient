//
// Created by nadavsklar on 1/3/19.
//

#include <include/Message.h>
#include <vector>
using namespace std;

FollowACK::FollowACK() : ACK(), numOfUsers(-1), userNameList(), followOrUnfollow('B'), currentNumOfUsers(0) {
    typeOfMessage = 4;
}

short FollowACK::getNumOfUsers() const {
    return numOfUsers;
}

void FollowACK::setNumOfUsers(short numOfUsers) {
    FollowACK::numOfUsers = numOfUsers;
}

const std::vector<std::string> &FollowACK::getUserNameList() const {
    return userNameList;
}

void FollowACK::addUserNameList(const std::string &userName) {
    FollowACK::userNameList.push_back(userName);
}

std::string FollowACK::messageString() { return "ACK 4 " + to_string(numOfUsers) + " " + getUsersString(); }

char FollowACK::getFollowOrUnfollow() const {
    return followOrUnfollow;
}

void FollowACK::setFollowOrUnfollow(char followOrUnfollow) {
    FollowACK::followOrUnfollow = followOrUnfollow;
}

int FollowACK::getCurrentNumOfUsers() const {
    return currentNumOfUsers;
}

void FollowACK::increaseCurrentNumOfUsers() {
    FollowACK::currentNumOfUsers++;
}

std::string FollowACK::getUsersString() {
    std::string result = "";
    for (int i = 0; i < userNameList.size(); i++) {
        if (i == userNameList.size() - 1)
            result += userNameList[i];
        else
            result += userNameList[i] + " ";
    }
    return result;
}

std::string FollowACK::getStringFromChar() { return followOrUnfollow + ""; }
