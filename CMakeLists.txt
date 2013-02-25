cmake_minimum_required( VERSION 2.8 )

include( FRCDeploy )

project( 422-Robot-2013 )

file( GLOB_RECURSE SOURCE_CODE *.cpp )

find_package( WPILib )

include_directories( ${WPILIB_INCLUDE_DIRS} )

add_executable( bin/422-robot-2013 ${SOURCE_CODE} )

target_link_libraries( bin/422-robot-2013 ${WPILIB_LIBRARY} )

add_make_deploy( bin/422-robot-2013 10.4.22.2 )
