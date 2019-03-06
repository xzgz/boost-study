# Collect source files
file(GLOB_RECURSE srcs ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

# Build each source file independently
foreach(source ${srcs})
    get_filename_component(name ${source} NAME_WE)
    add_executable(${name} ${source})
    target_link_libraries(${name} ${Boost_LINKER_LIBS})
#    caffe_default_properties(${name})

#    caffe_set_runtime_directory(${name} "${PROJECT_BINARY_DIR}/tools")
    set_target_properties(${name} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/array)
#    caffe_set_solution_folder(${name} tools)

    set_target_properties(${name} PROPERTIES INSTALL_RPATH_USE_LINK_PATH TRUE)
    install(TARGETS ${name} DESTINATION ${PROJECT_BINARY_DIR}/install/bin)

endforeach(source)