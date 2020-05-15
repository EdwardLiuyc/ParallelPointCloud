// MIT License

// Copyright (c) 2019 Edward Liu

// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#include "core/point_cloud.h"

using ppcl::core::concurrent::PointCloudXYZd;

int main(int, char**) {
  PointCloudXYZd ppcl_pointcloud;
  ppcl_pointcloud.emplace_back(1.1, 1.2, 1.3);
  ppcl_pointcloud.emplace_back(2.1, 2.2, 2.3);
  ppcl_pointcloud.emplace_back(3.1, 3.2, 3.3);
  LOG(INFO) << ppcl_pointcloud.size();

  for (auto& point : ppcl_pointcloud) {
    LOG(INFO) << point.channel("x");
  }

  return 0;
}
