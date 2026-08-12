#pragma once

#include "lve_camera.hpp"

#include <vulkan/vulkan.h>

namespace simple_shapes {
struct FrameInfo {
    int frameIndex;
    float frameTime;
    VkCommandBuffer commandBuffer;
    LveCamera& camera;
    VkDescriptorSet globalDescriptorSet;
};
} // namespace simple_shapes
