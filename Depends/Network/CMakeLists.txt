project(Network)

INCLUDE_DIRECTORIES(
${HtBaseC_INCLUDE}
${Depends_INCLUDE}
${Depends_INCLUDE}/libevent
${Depends_INCLUDE}/libevent/compat
${Depends_INCLUDE}/libevent/include
${Depends_INCLUDE}/libevent/WIN32-Code/nmake
)

file(GLOB_RECURSE SOURCE_FILE *.cpp)
file(GLOB_RECURSE HEADER_FILE *.hpp *.h)

ADD_LIBRARY(${PROJECT_NAME} ${SOURCE_FILE} ${HEADER_FILE})




