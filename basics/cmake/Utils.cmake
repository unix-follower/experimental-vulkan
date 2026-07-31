function(add_vulkan_app APP_NAME)
    set(multiValueArgs SOURCES LIBS)
    cmake_parse_arguments(ARG "" "" "${multiValueArgs}" ${ARGN})

    add_library(${APP_NAME}_core STATIC ${ARG_SOURCES})
    target_link_libraries(${APP_NAME}_core PUBLIC Vulkan::Vulkan glfw ${ARG_LIBS})
    target_include_directories(${APP_NAME}_core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
    target_compile_features(${APP_NAME}_core PUBLIC cxx_std_23)

    add_executable(${APP_NAME} main.cpp)
    target_link_libraries(${APP_NAME} PRIVATE ${APP_NAME}_core)
    set_target_properties(${APP_NAME} PROPERTIES OUTPUT_NAME ${APP_NAME})
endfunction()

# compile_shaders(<target> SOURCES <shader1> [<shader2> ...])
#
# Compiles the given GLSL shader sources to SPIR-V via glslc, placing
# outputs in ${CMAKE_CURRENT_BINARY_DIR}/shaders, and wires the result
# into <target> as a build dependency.
function(compile_shaders TARGET_NAME)
    cmake_parse_arguments(ARG "" "" "SOURCES" ${ARGN})

    if(NOT ARG_SOURCES)
        message(FATAL_ERROR "compile_shaders(${TARGET_NAME}): no SOURCES given")
    endif()

    set(shader_dir ${CMAKE_CURRENT_BINARY_DIR}/shaders)
    set(shader_outputs)

    foreach(shader_source ${ARG_SOURCES})
        get_filename_component(shader_name ${shader_source} NAME)
        set(shader_output ${shader_dir}/${shader_name}.spv)

        add_custom_command(
            OUTPUT ${shader_output}
            COMMAND ${CMAKE_COMMAND} -E make_directory ${shader_dir}
            COMMAND $<TARGET_FILE:Vulkan::glslc> ${shader_source} -o ${shader_output}
            DEPENDS ${shader_source}
            COMMENT "Compiling ${shader_name} to SPIR-V"
            VERBATIM
        )
        list(APPEND shader_outputs ${shader_output})
    endforeach()

    add_custom_target(${TARGET_NAME}_shaders ALL DEPENDS ${shader_outputs})
    add_dependencies(${TARGET_NAME} ${TARGET_NAME}_shaders)
endfunction()
