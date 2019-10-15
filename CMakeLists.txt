cmake_minimum_required(VERSION 3.14)
project(Ex1ISC105Sept2019 C)

set(CMAKE_C_STANDARD 99)

include_directories(librerias_comunes)

add_executable(punto1Main punto1/punto1Main.c punto1/punto1Lib.c punto1/punto1Lib.h)
add_executable(punto1MinUnit punto1/punto1MinUnit.c punto1/punto1Lib.c punto1/punto1Lib.h)
add_executable(punto2Main punto2/punto2Main.c punto2/punto2Lib.c punto2/punto2Lib.h)
add_executable(punto2MinUnit punto2/punto2MinUnit.c punto2/punto2Lib.c punto2/punto2Lib.h)
add_executable(punto3Main punto3/punto3Main.c punto3/punto3Lib.c punto3/punto3Lib.h)
add_executable(punto3MinUnit punto3/punto3MinUnit.c punto3/punto3Lib.c punto3/punto3Lib.h)
add_executable(punto4Main punto4/punto4Main.c punto4/punto4Lib.c punto4/punto4Lib.h)
add_executable(punto4MinUnit punto4/punto4MinUnit.c punto4/punto4Lib.c punto4/punto4Lib.h)
add_executable(punto5Main punto5/punto5Main.c punto5/punto5Lib.c punto5/punto5Lib.h)
add_executable(punto5MinUnit punto5/punto5MinUnit.c punto5/punto5Lib.c punto5/punto5Lib.h)
add_executable(bonoMain punto6Bono/bonoMain.c)