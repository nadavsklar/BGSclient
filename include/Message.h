//
// Created by nadavsklar on 1/3/19.
//

#ifndef BGSCLIENT_MESSAGE_H
#define BGSCLIENT_MESSAGE_H

using namespace std;

#include <string>
#include <vector>

class Message{
    protected:
        short opcode_;
    private:
        bool isReaded;

    public:
        Message(short opcode);
        short getOpcode_() const ;
        void setOpcode_(short opcode);
        bool IsReaded();
        void setIsReaded(bool isReaded);
        virtual std::string messageString();
};

class ACKOrError : public Message {

    protected:
        short typeOfMessage;

    public:
        ACKOrError(short opcode);
        short getTypeOfMessage();
        virtual std::string messageString();
        void setTypeOfMessage(short typeOfMessage);
};

class ACK : public ACKOrError {

    public:
        ACK();
        virtual std::string messageString();
};

class Error : public ACKOrError {

    public:
        Error();
        std::string messageString();
};

class Notification : public Message{

    private:
        char publicOrPrivate;
        std::string postingUser;
        std::string content;

    public:
        Notification();
        char getPublicOrPrivate() const;
        void setPublicOrPrivate(char publicOrPrivate);
        const std::string &getPostingUser() const;
        void setPostingUser(const std::string &postingUser);
        const std::string &getContent() const;
        void setContent(const std::string &content);
        std::string messageString();

    private:
        std::string getStringPrivateOrPublic();
};

class FollowACK : public ACK {

private:
    short numOfUsers;
    std::vector<std::string> userNameList;
    char followOrUnfollow;
    int currentNumOfUsers;

public:
    FollowACK();
    short getNumOfUsers() const;
    void setNumOfUsers(short numOfUsers);
    const std::vector<std::string> &getUserNameList() const;
    void addUserNameList(const std::string &userName);
    std::string messageString();
    char getFollowOrUnfollow() const;
    void setFollowOrUnfollow(char followOrUnfollow);
    int getCurrentNumOfUsers() const;
    void increaseCurrentNumOfUsers();

private:
    std::string getUsersString();
    std::string getStringFromChar();
};

class StatACK : public ACK {

private:
    short numOfPosts;
    short numOfFollowers;
    short numOfFollowing;
public:
    StatACK();
    short getNumOfPosts() const;
    void setNumOfPosts(short numOfPosts);
    short getNumOfFollowers() const;
    void setNumOfFollowers(short numOfFollowers);
    short getNumOfFollowing() const;
    void setNumOfFollowing(short numOfFollowing);
    std::string messageString();
};

class UserListACK : public  ACK {
private:
    short numOfUsers;
    std::vector<std::string> userNameList;
    int currentNumOfUsers;

public:
    UserListACK();
    short getNumOfUsers() const;
    void setNumOfUsers(short numOfUsers);
    const std::vector<std::string> &getUserNameList() const;
    void addUserNameList(const std::string &userName);
    std::string messageString();
    std::string getUsersString();
    int getCurrentNumOfUsers() const;
    void increaseCurrentNumOfUsers();
};
#endif //BGSCLIENT_MESSAGE_H
