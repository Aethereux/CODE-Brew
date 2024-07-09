cmake_minimum_required(VERSION 3.10)

# set the project name
project(CODE-Brew)

# include the Database directory
include_directories(../Database)

# add the UserUI executable
add_executable(UserUI ../src/User\ UI/userui.cpp ../src/User\ UI/MenuFunctions.cpp ../src/User UI/MenuFunctions.hs)

# add_executable(AdminUI ../src/Admin\ UI/adminui.cpp ../src/Admin\ UI/AdminFeatures.cpp ../src/Admin\ UI/VoucherSystem.cpp)

# Specify C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)