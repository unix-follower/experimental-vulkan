#pragma once

#include <string>
#include <vector>

namespace simple_shapes {
class LvePipeline {
  public:
    LvePipeline(const std::string& vertFilepath, const std::string& fragFilepath);

  private:
    static std::vector<char> readFile(const std::string& filepath);

    void createGraphicsPipeline(const std::string& vertFilepath, const std::string& fragFilepath);
};
} // namespace simple_shapes
