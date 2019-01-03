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
        int currentNumOfUsers;

    public:
        FollowACK() : ACK(), numOfUsers(-1), userNameList(), followOrUnfollow('B'), currentNumOfUsers(0) {
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

        void addUserNameList(const std::string &userName) {
            FollowACK::userNameList.push_back(userName);
        }

        std::string messageString() {return "ACK 4 " + getStringFromChar() + " " + getUsersString(); }

        char getFollowOrUnfollow() const {
            return followOrUnfollow;
        }

        void setFollowOrUnfollow(char followOrUnfollow) {
            FollowACK::followOrUnfollow = followOrUnfollow;
        }

        int getCurrentNumOfUsers() const {
            return currentNumOfUsers;
        }

        void increaseCurrentNumOfUsers() {
            FollowACK::currentNumOfUsers++;
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