//
// Created by nadavsklar on 1/3/19.
//

#ifndef BGSCLIENT_WRITETASK_H
#define BGSCLIENT_WRITETASK_H


#include "connectionHandler.h"
using namespace std;

class WriteTask {
    private:
        ConnectionHandler& handler;
        bool& shouldTerminate;
        bool& failLogout;
public:
        WriteTask(ConnectionHandler& handler, bool& shouldTerminate, bool& failLogout);
        void run();
};


#endif //BGSCLIENT_WRITETASK_H
