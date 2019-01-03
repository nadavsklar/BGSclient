//
// Created by nadavsklar on 1/3/19.
//

#ifndef BGSCLIENT_WRITETASK_H
#define BGSCLIENT_WRITETASK_H


#include "connectionHandler.h"

class WriteTask {
    private:
        ConnectionHandler* handler;
    public:
        WriteTask(ConnectionHandler* handler);
        void run();
};


#endif //BGSCLIENT_WRITETASK_H
