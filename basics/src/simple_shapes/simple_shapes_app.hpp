#pragma once

#include "lve_descriptors.hpp"
#include "lve_device.hpp"
#include "lve_game_object.hpp"
#include "lve_renderer.hpp"
#include "lve_window.hpp"

#include <memory>
#include <vector>

namespace simple_shapes {
class SimpleShapesApp {
  public:
    static constexpr int WIDTH = 800;
    static constexpr int HEIGHT = 600;

    SimpleShapesApp();
    ~SimpleShapesApp();

    SimpleShapesApp(const SimpleShapesApp&) = delete;
    SimpleShapesApp& operator=(const SimpleShapesApp&) = delete;

    void run();

  private:
    void loadGameObjects();

    LveWindow lveWindow{WIDTH, HEIGHT, "Hello Vulkan!"};
    LveDevice lveDevice{lveWindow};
    LveRenderer lveRenderer{lveWindow, lveDevice};

    // note: order of declarations matters
    std::unique_ptr<LveDescriptorPool> globalPool{};
    LveGameObject::Map gameObjects;
};
} // namespace simple_shapes
