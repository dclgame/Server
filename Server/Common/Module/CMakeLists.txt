SET_PROPERTY(GLOBAL PROPERTY USE_FOLDERS ON)

function(group_by_dir src_dir)
 
  foreach(FILE ${ARGN})
    # 获取文件绝对路径
   
    get_filename_component(FULL_NAME "${FILE}" ABSOLUTE)

    # 获取文件父路径
    get_filename_component(PARENT_DIR "${FULL_NAME}" PATH)

    # 移除父路径中的源码根路径 ARGV0 = CMAKE_CURRENT_SOURCE_DIR
    string(REPLACE "${ARGV0}" "" GROUP "${PARENT_DIR}")
  
    # 确保路径使用windows路径符号
    string(REPLACE "/" "\\" GROUP "${GROUP}")

  
#	set(GROUP "${GROUP}")
  # 将文件归组到 "Source Files" 和 "Header Files"
  #  if("${FILE}" MATCHES ".*\\.h")
  #    set(GROUP "Header Files${GROUP}")
  #  else()
  #    set(GROUP "Source Files${GROUP}")
  #  endif()
  
  # 筛选器
  source_group("${GROUP}" FILES "${FILE}")
 
  endforeach()
endfunction(group_by_dir)


#project(AdminServer)


file(GLOB_RECURSE ALL_FILE *.cpp *.h)
 
 group_by_dir("${CMAKE_CURRENT_SOURCE_DIR}" ${ALL_FILE})


 add_executable(${PROJECT_NAME}  ${ALL_FILE})



#SET_PROPERTY(TARGET ${PROJECT_NAME} PROPERTY FOLDER "Server")
 






#TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${LINK_LIB})
 



 
	

