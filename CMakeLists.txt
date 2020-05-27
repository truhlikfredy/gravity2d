cmake_minimum_required(VERSION 3.4)
project(gravity2d)

#set(CMAKE_CXX_FLAGS "-Wall -Wextra")

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        src/gravity2d.cpp
        src/types/vector2.cpp
        src/types/vector2.h
        src/frontend/display.cpp
        src/frontend/display.h
        src/utils/debounce.cpp
        src/utils/debounce.h
        src/types/object.h src/types/object.cpp)

add_executable(gravity2d ${SOURCE_FILES})

target_link_libraries(gravity2d sfml-graphics sfml-window sfml-system Threads::Threads)
