#pragma once

#include "lve_camera.hpp"
#include "lve_game_object.hpp"

#include <vulkan/vulkan.h>

namespace simple_shapes {
struct FrameInfo {
    int frameIndex;
    float frameTime;
    VkCommandBuffer commandBuffer;
    LveCamera& camera;
    VkDescriptorSet globalDescriptorSet;
    LveGameObject::Map& gameObjects;
};
} // namespace simple_shapes
