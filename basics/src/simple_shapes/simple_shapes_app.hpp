#pragma once

#include "lve_window.hpp"

namespace simple_shapes {
class SimpleShapesApp {
  public:
    static constexpr int WIDTH = 800;
    static constexpr int HEIGHT = 600;

    void run();

  private:
    LveWindow lveWindow{WIDTH, HEIGHT, "Hello Vulkan!"};
};
} // namespace simple_shapes
