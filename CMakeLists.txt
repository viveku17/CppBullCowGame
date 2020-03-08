cmake_minimum_required (VERSION 3.12.0)

project (UltimateCppTutorial)

set (CMAKE_CXX_STANDARD 14)

set(SRC_FILES main.cpp BullCowGame.cpp)

add_executable(${PROJECT_NAME} ${SRC_FILES})

