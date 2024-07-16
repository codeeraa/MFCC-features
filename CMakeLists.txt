cmake_minimum_required(VERSION 3.10)
project(MFCC)

set(CMAKE_CXX_STANDARD 17)

find_package(FFTW REQUIRED)
find_package(Eigen3 3.3 REQUIRED NO_MODULE)

include_directories(${FFTW_INCLUDES})
include_directories(${EIGEN3_INCLUDE_DIRS})

add_executable(MFCC src/main.cpp src/pre_emphasis.h src/framing.h src/hamming_window.h src/fft.h src/mel_filterbank.h src/dct.h)
target_link_libraries(MFCC fftw3 ${FFTW_LIBRARIES} Eigen3::Eigen)
