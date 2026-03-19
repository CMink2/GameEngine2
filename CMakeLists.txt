cmake_minimum_required(VERSION 3.10)

#project name
project(GameEngine VERSION 1.0)

#standard language
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

#headers and directories
include_directories(${PROJECT_SOURCE_DIR}/include)

# SDL2 라이브러리 설정
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

#source files
file(GLOB SOURCES "${CMAKE_SOURCE_DIR}/src/*.cpp")

#diagnostics: 출력해서 파일이 잡히는지 확인
message(STATUS "CMake source dir: ${CMAKE_SOURCE_DIR}")
message(STATUS "Found source files: ${SOURCES}")
if(NOT SOURCES)
  message(FATAL_ERROR "No source files found under ${CMAKE_SOURCE_DIR}/src — 빌드할 소스가 없습니다.")
endif()

#add executable
add_executable(GameEngine ${SOURCES})