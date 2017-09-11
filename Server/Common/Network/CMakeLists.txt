project(Network)

INCLUDE_DIRECTORIES(
${HtBaseC_INCLUDE}
${Depends_INCLUDE}/include/libevent
)

IF(WIN32)
INCLUDE_DIRECTORIES(
${Depends_INCLUDE}/include/libevent/WIN32-Code
${Depends_INCLUDE}/include/libevent/WIN32-Code/nmake
)
ENDIF(WIN32)


 
file(GLOB_RECURSE SOURCE_FILE *.cpp)
file(GLOB_RECURSE HEADER_FILE *.hpp *.h)

ADD_LIBRARY(${PROJECT_NAME} ${SOURCE_FILE} ${HEADER_FILE})




