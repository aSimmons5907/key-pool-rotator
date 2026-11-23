cmake_minimum_required(VERSION 3.16)
project(key-pool-rotator CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(keypoolrotator
    src/main.cpp
    src/pool.cpp
    src/proxy.cpp
    src/cooldowns.cpp
)

target_include_directories(keypoolrotator PRIVATE include)

if(WIN32)
    target_link_libraries(keypoolrotator PRIVATE userenv)
endif()
