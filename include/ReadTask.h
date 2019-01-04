//
// Created by nadavsklar on 1/3/19.
//

#ifndef BGSCLIENT_READTASK_H
#define BGSCLIENT_READTASK_H

#include <include/connectionHandler.h>
using namespace std;

class ReadTask {
    private:
        ConnectionHandler& handler;
        bool& shouldTerminate;
        bool& failLogout;
    public:
        ReadTask(ConnectionHandler& handler, bool& shouldTerminate, bool& failLogout);
        void run();
};


#endif //BGSCLIENT_READTASK_H
