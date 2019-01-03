//
// Created by nadavsklar on 1/3/19.
//

#include <src/Messages/ACK.cpp>

class StatACK : public ACK {

private:
    short numOfPosts;
    short numOfFollowers;
    short numOfFollowing;
public:
    StatACK() : ACK(), numOfFollowers(0), numOfPosts(0), numOfFollowing(0) {
        typeOfMessage = 8;
    }

    short getNumOfPosts() const {
        return numOfPosts;
    }

    void setNumOfPosts(short numOfPosts) {
        StatACK::numOfPosts = numOfPosts;
    }

    short getNumOfFollowers() const {
        return numOfFollowers;
    }

    void setNumOfFollowers(short numOfFollowers) {
        StatACK::numOfFollowers = numOfFollowers;
    }

    short getNumOfFollowing() const {
        return numOfFollowing;
    }

    void setNumOfFollowing(short numOfFollowing) {
        StatACK::numOfFollowing = numOfFollowing;
    }

    std::string messageString() { return "ACK 8 " + std::to_string(numOfPosts) + " " + std::to_string(numOfFollowers) +
    " " + std::to_string(numOfFollowing);}
};