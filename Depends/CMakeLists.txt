add_subdirectory(Module)
add_subdirectory(libevent)
add_subdirectory(Network)

SET_PROPERTY(TARGET Module Network libevent PROPERTY FOLDER "Depends")