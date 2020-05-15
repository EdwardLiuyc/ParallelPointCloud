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

#ifndef CORE_NON_CONCURRENT_POINT_CLOUD_H_
#define CORE_NON_CONCURRENT_POINT_CLOUD_H_

#include "core/point_cloud_base.h"

namespace ppcl {
namespace core {
namespace non_concurrent {

// clang-format off
using PointCloudXYZd =
  PointCloud<double, 3, std::vector,
    kPositionX,
    kPositionY,
    kPositionZ>;

using PointCloudXYZId =
  PointCloud<double, 4, std::vector,
    kPositionX,
    kPositionY,
    kPositionZ,
    kIntensity>;

using PointCloudXYZTd =
  PointCloud<double, 4, std::vector,
    kPositionX,
    kPositionY,
    kPositionZ,
    kTime>;

using PointCloudXYZITd =
  PointCloud<double, 5, std::vector,
    kPositionX,
    kPositionY,
    kPositionZ,
    kIntensity,
    kTime>;

using PointCloudXYZf =
  PointCloud<float, 3, std::vector,
    kPositionX,
    kPositionY,
    kPositionZ>;

using PointCloudXYZIf =
  PointCloud<float, 4, std::vector,
    kPositionX,
    kPositionY,
    kPositionZ,
    kIntensity>;

using PointCloudXYZTf =
  PointCloud<float, 4, std::vector,
    kPositionX,
    kPositionY,
    kPositionZ,
    kTime>;

using PointCloudXYZITf =
  PointCloud<float, 5, std::vector,
    kPositionX,
    kPositionY,
    kPositionZ,
    kIntensity,
    kTime>;
// clang-format on

}  // namespace non_concurrent
}  // namespace core
}  // namespace ppcl

#endif  // CORE_NON_CONCURRENT_POINT_CLOUD_H_
