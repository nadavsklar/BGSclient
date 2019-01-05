//
// Created by nadavsklar on 1/3/19.
//

#include "../include/Message.h"

using namespace std;

Notification::Notification() : Message(9), publicOrPrivate('B'), postingUser(""), content("") {}

char Notification::getPublicOrPrivate() const { return publicOrPrivate; }

void Notification::setPublicOrPrivate(char publicOrPrivate) { Notification::publicOrPrivate = publicOrPrivate; }

const std::string &Notification::getPostingUser() const { return postingUser; }

void Notification::setPostingUser(const std::string &postingUser) { Notification::postingUser = postingUser; }

const std::string &Notification::getContent() const { return content; }

void Notification::setContent(const std::string &content) { Notification::content = content; }

std::string Notification::messageString() { return "Notification " + getStringPrivateOrPublic() + " " + postingUser + " " + content; }

std::string Notification::getStringPrivateOrPublic() {
    switch (publicOrPrivate) {
        case '0':
            return "PM";
        case '1':
            return "Public";
        default:
            return "";
    }
}
