cmake_minimum_required(VERSION 3.21)
project(labo8)

set(CMAKE_CXX_STANDARD 20)

add_executable(labo8 main.cpp
                     annexe.cpp
                     annexe_def.h
                     annexe.h
                     Coordonnee.cpp
                     Coordonnee.h
                     Robot.cpp
                     Robot.h
                     Terrain_def.h
                     Terrain.h)
