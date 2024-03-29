cmake_minimum_required(VERSION 3.12)
project(BGSclient)


set(BOOST_ROOT "/path_to_boost_1_57_0")
set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
SET(PLATFORM_SPECIFIC_LIBS "-lpthread")


find_package(Boost 1.57.0 COMPONENTS filesystem regex)

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    add_executable(BGSclient
            include/connectionHandler.h
            src/connectionHandler.cpp
            src/echoClient.cpp
            makefile include/messageEncoderDecoder.h
            src/messageEncoderDecoder.cpp
            src/Messages/Message.cpp src/Messages/ACKOrError.cpp
            src/Messages/Error.cpp src/Messages/ACK.cpp
            src/Messages/Notification.cpp src/Messages/FollowACK.cpp
            src/Messages/StatACK.cpp src/Messages/UserListACK.cpp include/Message.h src/ReadTask.cpp include/ReadTask.h src/WriteTask.cpp include/WriteTask.h)
    target_link_libraries(BGSclient ${Boost_LIBRARIES})
endif()
set(CMAKE_CXX_STANDARD 11)
target_compile_features(BGSclient PUBLIC cxx_std_11)
include_directories(.)
include_directories(include)
include_directories(src)
target_link_libraries(BGSclient -lpthread)