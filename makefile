# All Targets
all: BGSclient

# Tool invocations
BGSclient: bin/ACK.o bin/ACKOrError.o bin/Error.o bin/FollowACK.o bin/Message.o bin/Notification.o bin/StatACK.o bin/UserListACK.o bin/connectionHandler.o bin/echoClient.o bin/messageEncoderDecoder.o bin/ReadTask.o bin/WriteTask.o
	@echo 'Building target: BGSclient'
	@echo 'Invoking: C++ Linker'
	g++ -o bin/BGSclient bin/ACK.o bin/ACKOrError.o bin/Error.o bin/FollowACK.o bin/Message.o bin/Notification.o bin/StatACK.o bin/UserListACK.o bin/connectionHandler.o bin/echoClient.o bin/messageEncoderDecoder.o bin/ReadTask.o bin/WriteTask.o
	@echo 'Finished building target: BGSclient'
	@echo ' '

# Depends on the source and header files
bin/ACK.o: src/Messages/ACK.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/ACK.o src/Messages/ACK.cpp

# Depends on the source and header files 
bin/ACKOrError.o: src/Messages/ACKOrError.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/ACKOrError.o src/Messages/ACKOrError.cpp

bin/Error.o: src/Messages/Error.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/Error.o src/Messages/Error.cpp

bin/FollowACK.o: src/Messages/FollowACK.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/FollowACK.o src/Messages/FollowACK.cpp

bin/Message.o: src/Messages/Message.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/Message.o src/Messages/Message.cpp

bin/Notification.o: src/Messages/Notification.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/Notification.o src/Messages/Notification.cpp

bin/StatACK.o: src/Messages/StatACK.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/StatACK.o src/Messages/StatACK.cpp

bin/UserListACK.o: src/Messages/UserListACK.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/UserListACK.o src/Messages/UserListACK.cpp

bin/connectionHandler.o: src/connectionHandler.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/connectionHandler.o src/connectionHandler.cpp

bin/echoClient.o: src/echoClient.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/echoClient.o src/echoClient.cpp

bin/messageEncoderDecoder.o: src/messageEncoderDecoder.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/messageEncoderDecoder.o src/messageEncoderDecoder.cpp

bin/ReadTask.o: src/ReadTask.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/ReadTask.o src/ReadTask.cpp

bin/WriteTask.o: src/WriteTask.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/WriteTask.o src/WriteTask.cpp

#Clean the build directory
clean: 
	rm -f bin/*



CFLAGS:=-c -Wall -Weffc++ -g -std=c++11 -Iinclude
LDFLAGS:=-lboost_system

all: BGSclient
	g++ -o bin/BGSclient bin/ACK.o bin/ACKOrError.o bin/Error.o bin/FollowACK.o bin/Message.o bin/Notification.o bin/StatACK.o bin/UserListACK.o bin/connectionHandler.o bin/echoClient.o bin/messageEncoderDecoder.o bin/ReadTask.o bin/WriteTask.o -pthread $(LDFLAGS)

BGSclient: bin/ACK.o bin/ACKOrError.o bin/Error.o bin/FollowACK.o bin/Message.o bin/Notification.o bin/StatACK.o bin/UserListACK.o bin/connectionHandler.o bin/echoClient.o bin/messageEncoderDecoder.o bin/ReadTask.o bin/WriteTask.o

bin/connectionHandler.o: src/connectionHandler.cpp
	g++ $(CFLAGS) -o bin/connectionHandler.o src/connectionHandler.cpp

bin/echoClient.o: src/echoClient.cpp
	g++ $(CFLAGS) -o bin/echoClient.o src/echoClient.cpp
bin/Task.o: src/Task.cpp
	g++ $(CFLAGS) -o bin/Task.o src/Task.cpp

.PHONY: clean
clean:
	rm -f bin/*