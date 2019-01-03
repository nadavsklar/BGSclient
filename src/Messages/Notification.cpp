//
// Created by nadavsklar on 1/3/19.
//

#include <src/Messages/Message.cpp>

class Notification : public Message{

private:
    char publicOrPrivate;
    std::string postingUser;
    std::string content;

public:
    Notification() : Message(9), publicOrPrivate('B'), postingUser(nullptr), content(nullptr) {}

    char getPublicOrPrivate() const {
        return publicOrPrivate;
    }

    void setPublicOrPrivate(char publicOrPrivate) {
        Notification::publicOrPrivate = publicOrPrivate;
    }

    const std::string &getPostingUser() const {
        return postingUser;
    }

    void setPostingUser(const std::string &postingUser) {
        Notification::postingUser = postingUser;
    }

    const std::string &getContent() const {
        return content;
    }

    void setContent(const std::string &content) {
        Notification::content = content;
    }

    std::string messageString() { return "Notification " + getStringPrivateOrPublic() + " " + postingUser + " " + content; }

    private:
        std::string getStringPrivateOrPublic() {
            switch (publicOrPrivate) {
                case '0':
                    return "PM";
                case '1':
                    return "Private";
                default:
                    return "";
            }
        }
};