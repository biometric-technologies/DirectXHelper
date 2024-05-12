cmake_minimum_required(VERSION 3.10)

project(DirectXHelper VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_definitions(-DDIRECTXHELPERLIB_EXPORTS)

include_directories(${PROJECT_SOURCE_DIR}/include)

add_library(DirectXHelper SHARED
        src/DirectXHelper.cpp
)

target_link_libraries(DirectXHelper dxgi)

add_executable(TestApp test/Test.cpp)

target_link_libraries(TestApp DirectXHelper)