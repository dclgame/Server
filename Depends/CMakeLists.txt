add_subdirectory(Module)
add_subdirectory(Network)


SET_PROPERTY(TARGET Module Network PROPERTY FOLDER "Depends")