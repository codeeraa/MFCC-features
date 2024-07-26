cmake_minimum_required(VERSION 3.10)
project(mfcc_feature)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(FFTW3 CONFIG REQUIRED)

find_package(FFTW3f CONFIG REQUIRED)

find_package(FFTW3l CONFIG REQUIRED)

include_directories(include)

set(SOURCE_FILES
    src/main.cpp
)

add_executable(mfcc_feature ${SOURCE_FILES})

target_link_libraries(mfcc_feature PRIVATE FFTW3::fftw3)
target_link_libraries(mfcc_feature PRIVATE FFTW3::fftw3f)
target_link_libraries(mfcc_feature PRIVATE FFTW3::fftw3l)
