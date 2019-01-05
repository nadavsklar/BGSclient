CFLAGS:=-c -Wall -Weffc++ -g -std=c++11 -Iinclude
LDFLAGS:=-lboost_system

all: BGSclient
	g++ -o bin/BGSclient bin/connectionHandler.o bin/echoClient.o bin/ACK.o bin/ACKOrError.o bin/Error.o bin/FollowACK.o bin/Message.o bin/Notification.o bin/StatACK.o bin/UserListACK.o bin/messageEncoderDecoder.o bin/ReadTask.o bin/WriteTask.o -pthread $(LDFLAGS)

BGSclient: bin/connectionHandler.o bin/echoClient.o bin/ACK.o bin/ACKOrError.o bin/Error.o bin/FollowACK.o bin/Message.o bin/Notification.o bin/StatACK.o bin/UserListACK.o bin/messageEncoderDecoder.o bin/ReadTask.o bin/WriteTask.o

bin/connectionHandler.o: src/connectionHandler.cpp
	g++ $(CFLAGS) -o bin/connectionHandler.o src/connectionHandler.cpp

bin/echoClient.o: src/echoClient.cpp
	g++ $(CFLAGS) -o bin/echoClient.o src/echoClient.cpp

bin/ACK.o: src/Messages/ACK.cpp
	g++ $(CFLAGS) -o bin/ACK.o src/Messages/ACK.cpp

bin/ACKOrError.o: src/Messages/ACKOrError.cpp
	g++ $(CFLAGS) -o bin/ACKOrError.o src/Messages/ACKOrError.cpp

bin/Error.o: src/Messages/Error.cpp
	g++ $(CFLAGS) -o bin/Error.o src/Messages/Error.cpp

bin/FollowACK.o: src/Messages/FollowACK.cpp
	g++ $(CFLAGS) -o bin/FollowACK.o src/Messages/FollowACK.cpp

bin/Message.o: src/Messages/Message.cpp
	g++ $(CFLAGS) -o bin/Message.o src/Messages/Message.cpp

bin/Notification.o: src/Messages/Notification.cpp
	g++ $(CFLAGS) -o bin/Notification.o src/Messages/Notification.cpp

bin/StatACK.o: src/Messages/StatACK.cpp
	g++ $(CFLAGS) -o bin/StatACK.o src/Messages/StatACK.cpp

bin/UserListACK.o: src/Messages/UserListACK.cpp
	g++ $(CFLAGS) -o bin/UserListACK.o src/Messages/UserListACK.cpp

bin/messageEncoderDecoder.o: src/messageEncoderDecoder.cpp
	g++ $(CFLAGS) -o bin/messageEncoderDecoder.o src/messageEncoderDecoder.cpp

bin/ReadTask.o: src/ReadTask.cpp
	g++ $(CFLAGS) -o bin/ReadTask.o src/ReadTask.cpp

bin/WriteTask.o: src/WriteTask.cpp
	g++ $(CFLAGS) -o bin/WriteTask.o src/WriteTask.cpp

.PHONY: clean
clean:
	rm -f bin/*