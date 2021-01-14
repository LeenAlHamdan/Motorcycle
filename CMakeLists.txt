cmake_minimum_required(VERSION 3.15)
project(Motorcycle)

set(CMAKE_CXX_STANDARD 14)

add_executable(Motorcycle main.cpp Customer.h Address.h Record.h Motorcycle.h LinkedListRecords.h LinkedListMotorcycles.h)