//
// Created by nadavsklar on 1/3/19.
//

#include <src/Messages/ACK.cpp>
#include <vector>

class UserListACK : public  ACK {
private:
    short numOfUsers;
    std::vector<std::string> userNameList;

public:
    UserListACK() : ACK(), numOfUsers(0), userNameList() {
        typeOfMessage = 7;
    }

    short getNumOfUsers() const {
        return numOfUsers;
    }

    void setNumOfUsers(short numOfUsers) {
        UserListACK::numOfUsers = numOfUsers;
    }

    const std::vector<std::string> &getUserNameList() const {
        return userNameList;
    }

    void setUserNameList(const std::vector<std::string> &userNameList) {
        UserListACK::userNameList = userNameList;
    };

    std::string messageString() { return "ACK 7 " + std::to_string(numOfUsers) + " " + getUsersString();}

    std::string getUsersString() {
        std::string result = "";
        for (int i = 0; i < userNameList.size(); i++) {
            if (i == userNameList.size() - 1)
                result += userNameList[i];
            else
                result += userNameList[i] + " ";
        }
        return result;
    }
};