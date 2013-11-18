cmake_minimum_required(VERSION 2.8)
include(FRCDeploy)

project(NidhoggCompetition)
find_package(WPILib)
include_directories(SYSTEM ${WPILib_INCLUDE_DIRS})

file(GLOB_RECURSE SOURCE_CODE *.cpp)

add_executable(nidhogg-competition ${SOURCE_CODE})
target_link_libraries(nidhogg-competition ${WPILib_LIBRARY})

add_make_deploy(nidhogg-competition 10.4.22.2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -DUSE_CPP_11")
