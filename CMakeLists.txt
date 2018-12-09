cmake_minimum_required( VERSION 2.8.9 )

project( testStatePattern )

include_directories( $CMAKE_SOURCE_DIR )

add_definitions( -std=c++11 )

add_executable( testStatePattern testStatePattern.cpp )

#target_link_libraries( testStatePattern gsl gslcblas png z m )

