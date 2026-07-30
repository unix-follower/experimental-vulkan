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

function(compile_shaders TARGET_NAME)
    foreach(SHADER ${ARGN})
        get_filename_component(SHADER_NAME ${SHADER} NAME)
        set(SPIRV "${CMAKE_CURRENT_BINARY_DIR}/shaders/${SHADER_NAME}.spv")
        add_custom_command(
            OUTPUT ${SPIRV}
            COMMAND Vulkan::glslc ${CMAKE_CURRENT_SOURCE_DIR}/${SHADER} -o ${SPIRV}
            DEPENDS ${SHADER}
        )
        list(APPEND SPIRV_BINARIES ${SPIRV})
    endforeach()
    add_custom_target(${TARGET_NAME}_shaders DEPENDS ${SPIRV_BINARIES})
    add_dependencies(${TARGET_NAME} ${TARGET_NAME}_shaders)
endfunction()
