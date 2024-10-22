cmake_minimum_required(VERSION 3.29)
project(l1)

set(CMAKE_CXX_STANDARD 20)

add_executable(l1 main.cpp
        Keeper.cpp
        Keeper.h
        Monster.cpp
        Monster.h
        Hero.h
        PositiveHero.cpp
        PositiveHero.h
        Villain.cpp
        Villain.h)
