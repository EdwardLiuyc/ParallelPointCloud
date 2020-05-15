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

#ifndef CORE_CONCORRENT_POINT_CLOUD_H_
#define CORE_CONCORRENT_POINT_CLOUD_H_

#include "core/point_cloud_base.h"

// some documentation for tbb
// A concurrent_vector meets all requirements for a Container and a Reversible
// Container as specified in the ISO C++ standard. It does not meet the
// Sequence requirements due to absence of methods insert() and erase(). A
// concurrent_vector is a container with the following features:
// - Random access by index. The index of the first element is zero.
// - Multiple threads can grow the container and append new elements
// concurrently.
// - Growing the container does not invalidate existing iterators or indices.

#include <tbb/concurrent_unordered_map.h>
#include <tbb/concurrent_vector.h>

namespace ppcl {
namespace core {
namespace concurrent {

// clang-format off
using PointCloudXYZd =
  PointCloud<double, 3, tbb::concurrent_vector,
    kPositionX,
    kPositionY,
    kPositionZ>;

using PointCloudXYZId =
  PointCloud<double, 4, tbb::concurrent_vector,
    kPositionX,
    kPositionY,
    kPositionZ,
    kIntensity>;

using PointCloudXYZTd =
  PointCloud<double, 4, tbb::concurrent_vector,
    kPositionX,
    kPositionY,
    kPositionZ,
    kTime>;

using PointCloudXYZITd =
  PointCloud<double, 5, tbb::concurrent_vector,
    kPositionX,
    kPositionY,
    kPositionZ,
    kIntensity,
    kTime>;

using PointCloudXYZf =
  PointCloud<float, 3, tbb::concurrent_vector,
    kPositionX,
    kPositionY,
    kPositionZ>;

using PointCloudXYZIf =
  PointCloud<float, 4, tbb::concurrent_vector,
    kPositionX,
    kPositionY,
    kPositionZ,
    kIntensity>;

using PointCloudXYZTf =
  PointCloud<float, 4, tbb::concurrent_vector,
    kPositionX,
    kPositionY,
    kPositionZ,
    kTime>;

using PointCloudXYZITf =
  PointCloud<float, 5, tbb::concurrent_vector,
    kPositionX,
    kPositionY,
    kPositionZ,
    kIntensity,
    kTime>;
// clang-format on

}  // namespace concurrent
}  // namespace core
}  // namespace ppcl

#endif  // CORE_CONCORRENT_POINT_CLOUD_H_
