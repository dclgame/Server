cmake_minimum_required(VERSION 3.1)


SET_PROPERTY(GLOBAL PROPERTY USE_FOLDERS ON)

SET(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/Cmake)
SET(CMAKE_USE_RELATIVE_PATHS ON)
IF(UNIX)
set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -rdynamic -ggdb") 
set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall") 


ELSE(UNIX)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MDd /Zi /Od /Ob0 /RTC1") 
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_DEBUG} /MD /O2 /Ob2 /DNDEBUG")
ENDIF(UNIX)

project(Server)

set(CMAKE_CONFIGURATION_TYPES "Debug;Release")


set(CMAKE_BUILD_TYPE "Debug")



IF(WIN32)
SET(LINK_LIB HtBaseC)
ELSE(WIN32)
#SET(LINK_LIB HtBaseC dl rt)
SET(LINK_LIB HtBaseC)
ENDIF(WIN32)

 


set(Common_INCLUDE ${CMAKE_SOURCE_DIR}/Server/Common)
set(Depends_INCLUDE ${CMAKE_SOURCE_DIR}/Depends)
set(HtBaseC_INCLUDE ${CMAKE_SOURCE_DIR}/HtBaseC)

SET(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
SET(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)

#IF(WIN32)
#include_directories(${SolutionDir}/Dependencies/libevent/WIN32-Code/)


add_subdirectory(HtBaseC)
add_subdirectory(Depends)

add_subdirectory(Server)
