cmake_minimum_required (VERSION 2.6)

project (projRb)

#file(GLOB_RECURSE SOURCES RELATIVE ${CMAKE_SOURCE_DIR} "*.cpp")
file(GLOB_RECURSE SOURCES RELATIVE ${CMAKE_SOURCE_DIR} "projRb.cpp")
#file(GLOB_RECURSE SOURCES RELATIVE ${CMAKE_SOURCE_DIR})

#add_executable(projRb projRb.cpp)
list(REMOVE_ITEM SOURCES ${CMAKE_SOURCE_DIR}/lit_capteur.cpp)
add_executable(projRb ${SOURCES})
file(GLOB_RECURSE SOURCES RELATIVE ${CMAKE_SOURCE_DIR} "*.cpp")
