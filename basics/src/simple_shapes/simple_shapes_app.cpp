#include "simple_shapes_app.hpp"

namespace simple_shapes {

void SimpleShapesApp::run()
{
    while (!lveWindow.shouldClose()) {
        glfwPollEvents();
    }
}
} // namespace simple_shapes
