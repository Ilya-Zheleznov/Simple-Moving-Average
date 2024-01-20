cmake_minimum_required(VERSION 2.8)

project(SMA)

include_directories(lib)

set(SOURCE_EXE src/main.cpp)

set(SOURCE_LIB lib/simplemovingaverage.cpp)

set(HEADER_LIB lib/simplemovingaverage.h)

add_library(sma STATIC ${SOURCE_LIB})

add_executable(main ${SOURCE_EXE})

target_link_libraries(main sma)
