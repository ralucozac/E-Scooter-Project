cmake_minimum_required(VERSION 3.24)
project(Labor4_OOP)

set(CMAKE_CXX_STANDARD 17)

add_executable(Labor4_OOP App/Shop.cpp Domain/Domain.h Domain/Domain.cpp UI/UI.h UI/UI.cpp Controller/Controller.h Controller/Controller.cpp Repository/Repository.cpp Repository/Repository.h)
