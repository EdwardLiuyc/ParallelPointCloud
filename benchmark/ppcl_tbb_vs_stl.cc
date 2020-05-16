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

#include <pcl/point_cloud.h>
#include <pcl/point_types.h>

#include "core/concorrent/point_cloud.h"
#include "core/non_concurrent/point_cloud.h"

#include "benchmark/performance/simple_prof.h"

using CuncurrentPointCloudXYZD = ppcl::core::concurrent::PointCloudXYZd;
using NonCuncurrentPointCloudXYZD = ppcl::core::non_concurrent::PointCloudXYZd;

int main(int, char**) {
  std::mt19937 prng = std::mt19937(42);
  std::uniform_real_distribution<double> distribution =
      std::uniform_real_distribution<double>(100., 100.);

  const int size = 10000000;
  std::vector<Eigen::Vector3d> random_data;
  for (int i = 0; i < size; ++i) {
    random_data.emplace_back(distribution(prng), distribution(prng),
                             distribution(prng));
  }

  {
    REGISTER_BLOCK("ppcl_with_tbb");
    CuncurrentPointCloudXYZD pointcloud;
    for (int i = 0; i < size; ++i) {
      pointcloud.emplace_back();
    }
  }

  {
    REGISTER_BLOCK("ppcl_with_stl");
    // NonCuncurrentPointCloudXYZD pointcloud2;
    // for (const auto& data : random_data) {
    //   pointcloud2.emplace_back(data[0], data[1], data[2]);
    // }
    pcl::PointCloud<pcl::PointXYZ> pointcloud;
    for (const auto& data : random_data) {
      pointcloud.push_back(pcl::PointXYZ(data[0], data[1], data[2]));
    }
  }

  return 0;
}
