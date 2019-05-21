cmake_minimum_required(VERSION 3.12)
project(tableau)

set(CMAKE_C_STANDARD 11)

add_executable(Tri sources/main.c headers/parametres.h sources/parametres.c headers/personnes.h sources/Fleche.c headers/algosutilises.h)