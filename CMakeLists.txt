cmake_minimum_required(VERSION 3.1)


SET_PROPERTY(GLOBAL PROPERTY USE_FOLDERS ON)

SET(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/Cmake)
SET(CMAKE_USE_RELATIVE_PATHS ON)
IF(UNIX)
set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -rdynamic -ggdb") 
set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall") 

add_definitions(-std=c++11)

ELSE(UNIX)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MDd /Zi /Od /Ob0 /RTC1") 
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_DEBUG} /MD /O2 /Ob2 /DNDEBUG")
ENDIF(UNIX)

project(Server)

set(CMAKE_CONFIGURATION_TYPES "Debug;Release")


set(CMAKE_BUILD_TYPE "Debug")

set(Depends_INCLUDE ${CMAKE_SOURCE_DIR}/Depends)
set(HtBaseC_INCLUDE ${CMAKE_SOURCE_DIR}/HtBaseC)
set(Common_INCLUDE ${CMAKE_SOURCE_DIR}/Server/Common)
IF(UNIX)
set(DEPENDS_LIBS ${CMAKE_SOURCE_DIR}/depends/lib)
ELSE(UNIX)
set(DEPENDS_LIBS ${CMAKE_SOURCE_DIR}/depends/lib/win32)
ENDIF(UNIX)


SET(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
SET(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)

SET(LIB_DIR ${EXECUTABLE_OUTPUT_PATH} ${DEPENDS_LIBS})

SET(INCLUDE_DIR ${CMAKE_SOURCE_DIR} ${HtBaseC_INCLUDE} ${Depends_INCLUDE} ${Common_INCLUDE})

#文件目录 库文件目录
INCLUDE_DIRECTORIES(${INCLUDE_DIR})
LINK_DIRECTORIES(${LIB_DIR})




IF(WIN32)
SET(LINK_LIB  HtBaseC.lib libevent.lib libevent_core.lib)
ELSE(WIN32)
#SET(LINK_LIB HtBaseC dl rt)
SET(LINK_LIB HtBaseC.a libevent.a libevent_core.a dl rt)
ENDIF(WIN32)



INCLUDE_DIRECTORIES(
${HtBaseC_INCLUDE}
${Common_INCLUDE}/Module
${Common_INCLUDE}/Network
)


if(WIN32)
INCLUDE_DIRECTORIES(
${Depends_INCLUDE}/include/libevent
${Depends_INCLUDE}/include/libevent/WIN32-Code
${Depends_INCLUDE}/include/libevent/WIN32-Code/nmake
)
ELSE(WIN32)
INCLUDE_DIRECTORIES(
${Depends_INCLUDE}/include/libevent
)
ENDIF(WIN32)



 


add_subdirectory(HtBaseC)
add_subdirectory(Server)