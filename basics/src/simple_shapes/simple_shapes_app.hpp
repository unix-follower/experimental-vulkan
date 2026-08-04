#pragma once

#include "lve_device.hpp"
#include "lve_model.hpp"
#include "lve_pipeline.hpp"
#include "lve_swap_chain.hpp"
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
    void loadModels();
    void createPipelineLayout();
    void createPipeline();
    void createCommandBuffers();
    void drawFrame();

    LveWindow lveWindow{WIDTH, HEIGHT, "Hello Vulkan!"};
    LveDevice lveDevice{lveWindow};
    LveSwapChain lveSwapChain{lveDevice, lveWindow.getExtent()};
    std::unique_ptr<LvePipeline> lvePipeline;
    VkPipelineLayout pipelineLayout;
    std::vector<VkCommandBuffer> commandBuffers;
    std::unique_ptr<LveModel> lveModel;
};
} // namespace simple_shapes
