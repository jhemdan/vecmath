cmake_minimum_required(VERSION 2.6)

project(vecmath)

include_directories(include)

set(VEC_HEADERS
	"include/vecmath/vector.hpp"
	"include/vecmath/matrix.hpp"
	"include/vecmath/pi.hpp"
	"include/vecmath/fwd.hpp"
)

set(VEC_SOURCES
	"src/vector.cpp"
	"src/matrix.cpp"
	"src/pi.cpp"
)

source_group("include\\vecmath" FILES ${VEC_HEADERS})
source_group("src" FILES ${VEC_SOURCES})

add_library(vecmath ${VEC_HEADERS} ${VEC_SOURCES})

if(NOT MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
endif()