cmake_minimum_required(VERSION 3.21)
project(labo8)

set(CMAKE_CXX_STANDARD 20)

add_executable(labo8 main.cpp annexe.h annexe_def.h Robot.cpp Robot.h Terrain.cpp Terrain.h Coordonnee.cpp Coordonnee.h)
