add_vulkan_app(simple_shapes
    SOURCES
        simple_shapes_app.cpp
        simple_shapes_app.hpp
        lve_window.cpp
        lve_window.hpp
        lve_pipeline.cpp
        lve_pipeline.hpp
)

compile_shaders(simple_shapes
    SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/shaders/simple_shader.vert
        ${CMAKE_CURRENT_SOURCE_DIR}/shaders/simple_shader.frag
)
