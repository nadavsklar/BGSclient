//
// Created by nadavsklar on 1/3/19.
//

#include <include/Message.h>

using namespace std;


StatACK::StatACK() : ACK(), numOfFollowers(-1), numOfPosts(-1), numOfFollowing(-1) { typeOfMessage = 8; }

short StatACK::getNumOfPosts() const { return numOfPosts; }

void StatACK::setNumOfPosts(short numOfPosts) { StatACK::numOfPosts = numOfPosts; }

short StatACK::getNumOfFollowers() const { return numOfFollowers; }

void StatACK::setNumOfFollowers(short numOfFollowers) { StatACK::numOfFollowers = numOfFollowers; }

short StatACK::getNumOfFollowing() const { return numOfFollowing; }

void StatACK::setNumOfFollowing(short numOfFollowing) { StatACK::numOfFollowing = numOfFollowing; }

std::string StatACK::messageString() {
    return "ACK 8 " + std::to_string(numOfPosts) + " " + std::to_string(numOfFollowers) +
           " " + std::to_string(numOfFollowing);
}
