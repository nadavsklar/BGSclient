//
// Created by nadavsklar on 1/3/19.
//

#include <src/Messages/ACK.cpp>
#include <vector>

class FollowACK : public ACK {

    private:
        short numOfUsers;
        std::vector<std::string> userNameList;
        char followOrUnfollow;

    public:
        FollowACK() : ACK(), numOfUsers(0), userNameList(), followOrUnfollow('B') {
            typeOfMessage = 4;
        }

        short getNumOfUsers() const {
            return numOfUsers;
        }

        void setNumOfUsers(short numOfUsers) {
            FollowACK::numOfUsers = numOfUsers;
        }

        const std::vector<std::string> &getUserNameList() const {
            return userNameList;
        }

        void setUserNameList(const std::vector<std::string> &userNameList) {
            FollowACK::userNameList = userNameList;
        }

        std::string messageString() {return "ACK 4 " + getStringFromChar() + " " + getUsersString(); }

        char getFollowOrUnfollow() const {
            return followOrUnfollow;
        }

        void setFollowOrUnfollow(char followOrUnfollow) {
            FollowACK::followOrUnfollow = followOrUnfollow;
        }

    private:
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

        std::string getStringFromChar() { return followOrUnfollow + "";}

};