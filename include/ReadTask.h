//
// Created by nadavsklar on 1/3/19.
//

#ifndef BGSCLIENT_READTASK_H
#define BGSCLIENT_READTASK_H

#include <include/connectionHandler.h>


class ReadTask {
    private:
        ConnectionHandler* handler;
    public:
        ReadTask(ConnectionHandler* handler);
        void run();
};


#endif //BGSCLIENT_READTASK_H
