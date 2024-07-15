cmake_minimum_required(VERSION 3.27)
project(CODE_Brew)

set(CMAKE_CXX_STANDARD 14)

include_directories("src/Admin UI")
include_directories(src/Database)
include_directories("src/User UI")

add_executable(CODE_Brew
        "src/User UI/MenuFunctions.cpp"
        "src/User UI/MenuFunctions.h"
        "src/User UI/userui.cpp")

set(CMAKE_EXE_LINKER_FLAGS "-static")