cmake_minimum_required(VERSION 3.10)
project(wordly)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(wordly 
    main.cpp
    wordle_game.cpp
    wordle_game.h
    constants.h)
