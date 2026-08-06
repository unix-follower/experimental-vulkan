#pragma once

#include "lve_device.hpp"
#include "lve_game_object.hpp"
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
    void loadGameObjects();
    void createPipelineLayout();
    void createPipeline();
    void createCommandBuffers();
    void freeCommandBuffers();
    void drawFrame();
    void recreateSwapChain();
    void recordCommandBuffer(int imageIndex);
    void renderGameObjects(VkCommandBuffer commandBuffer);

    LveWindow lveWindow{WIDTH, HEIGHT, "Hello Vulkan!"};
    LveDevice lveDevice{lveWindow};
    std::unique_ptr<LveSwapChain> lveSwapChain;
    std::unique_ptr<LvePipeline> lvePipeline;
    VkPipelineLayout pipelineLayout;
    std::vector<VkCommandBuffer> commandBuffers;
    std::vector<LveGameObject> gameObjects;
};
} // namespace simple_shapes
