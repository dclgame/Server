project(Common)

file(GLOB_RECURSE SOURCE_FILE *.cpp)
file(GLOB_RECURSE HEADER_FILE *.h)



ADD_LIBRARY(${PROJECT_NAME} ${SOURCE_FILE} ${HEADER_FILE})
 

 
	

