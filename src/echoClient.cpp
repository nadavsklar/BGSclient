#include <stdlib.h>
#include "../include/connectionHandler.h"
#include "../include/messageEncoderDecoder.h"
#include "../include/ReadTask.h"
#include "../include/WriteTask.h"
#include <thread>

using namespace std;
/**
* This code assumes that the server replies the exact text the client sent it (as opposed to the practical session example)
*/
int main (int argc, char *argv[]) {
    if (argc < 3) {
        std::cerr << "Usage: " << argv[0] << " host port" << std::endl << std::endl;
        return -1;
    }
    std::string host = argv[1];
    short port = atoi(argv[2]);

    //std::string host = "127.0.0.1";
    //short port = 7777;

    ConnectionHandler connectionHandler(host, port);
    if (!connectionHandler.connect()) {
        std::cerr << "Cannot connect to " << host << ":" << port << std::endl;
        return 1;
    }

    bool shouldTerminate = false;
    bool logoutSuccess = false;
    ReadTask readTask(connectionHandler, shouldTerminate, logoutSuccess);
    WriteTask writeTask(connectionHandler, shouldTerminate, logoutSuccess);

    std::thread readThread(&ReadTask::run, &readTask);
    std::thread writeThread(&WriteTask::run, &writeTask);

    writeThread.join();
    readThread.join();

    return 0;
}
