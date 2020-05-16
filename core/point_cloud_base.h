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

#ifndef CORE_POINT_CLOUD_BASE_H_
#define CORE_POINT_CLOUD_BASE_H_

#include <glog/logging.h>
#include <Eigen/Eigen>
#include <array>
#include <map>
#include <memory>
#include <set>
#include <string>
#include <vector>

namespace ppcl {
namespace core {

enum ChannelType : uint8_t {
  kPositionX,
  kPositionY,
  kPositionZ,
  kTime,
  kIntensity,
  kGrayScale,
  kSupportedChannelCount,
  kNoneType
};

template <typename Scalar, int Dim,
          template <typename, typename = std::allocator<Scalar>>
          class Container,
          ChannelType t0 = kNoneType, ChannelType t1 = kNoneType,
          ChannelType t2 = kNoneType, ChannelType t3 = kNoneType,
          ChannelType t4 = kNoneType, ChannelType t5 = kNoneType,
          ChannelType t6 = kNoneType, ChannelType t7 = kNoneType>
class PointCloud {
 public:
  PointCloud() {
    CHECK_GT(Dim, 0);
    CHECK_LT(Dim, kSupportedChannelCount);

    const std::string channel_names[kSupportedChannelCount] = {
        "x", "y", "z", "time", "intensity", "grayscale"};

    ChannelType types[] = {t0, t1, t2, t3, t4, t5, t6, t7};
    for (int i = 0; i < Dim; ++i) {
      CHECK(types[i] < kSupportedChannelCount);
      channels_.push_back(types[i]);
      name_to_index_[channel_names[types[i]]] = i;
    }
    CHECK_EQ(Dim, static_cast<int>(name_to_index_.size()))
        << "You have defined the same kind of channels!";
  }

  ~PointCloud() = default;

  class Point {
   public:
    // default constrcutor
    Point() { data_.setZero(); }

    // constrcutor with all raw data
    template <typename... Args>
    explicit Point(Args&&... args) {
      init(args...);
      CHECK_EQ(init_index_, Dim)
          << "Init the point with wrong dimension of data.";
    }

    // accessor
    inline Scalar& operator[](size_t n) { return data_(n, 0); }
    inline Scalar& operator[](const std::string& channel_name) {
      CHECK_NE(channel_name_index_->count(channel_name), 0);
      return data_(channel_name_index_->at(channel_name), 0);
    }
    inline Scalar& channel(const std::string& channel_name) {
      return (*this)[channel_name];
    }

    EIGEN_MAKE_ALIGNED_OPERATOR_NEW

    friend class PointCloud;

   private:
    Eigen::Matrix<Scalar, Dim, 1> data_;
    std::map<std::string, int>* channel_name_index_ = nullptr;

    // for variadic constructor
    int init_index_ = 0;
    void init(Scalar d) {
      data_(init_index_, 0) = d;
      init_index_++;
    }

    template <typename... Rest>
    void init(Scalar first, Rest&&... rest) {
      data_(init_index_, 0) = first;
      init_index_++;
      init(rest...);
    }
  };

  using InnerPointsContainer = Container<Point>;
  using iterator = typename InnerPointsContainer::iterator;
  using const_iterator = typename InnerPointsContainer::const_iterator;
  using Ptr = typename std::shared_ptr<PointCloud>;
  using ConstPtr = typename std::shared_ptr<const PointCloud>;

  // Element access
  inline Point at(size_t n) { return points_.at(n); }
  inline Point& operator[](size_t n) { return points_[n]; }
  inline Point& front() { return points_.front(); }
  inline Point& back() { return points_.back(); }

  // Iterators
  inline iterator begin() { return points_.begin(); }
  inline iterator end() { return points_.end(); }
  inline const_iterator cbegin() const { return points_.cbegin(); }
  inline const_iterator cend() const { return points_.cend(); }
  // no need of reverse iterators
  // so, no implementation of rbegin, rend, crbegin, crend

  // Capacity
  size_t size() const { return points_.size(); }
  size_t max_size() const { return points_.max_size(); }
  bool empty() const { return points_.empty(); }
  inline void reserve(size_t n) { points_.reserve(n); }
  inline void shrink_to_fit() { points_.shrink_to_fit(); }

  // Modifiers
  template <class... Args>
  void emplace_back(Args&&... args) {
    points_.emplace_back(args...);
    points_.back().channel_name_index_ = &name_to_index_;
  }
  void push_back(const Point& point) {
    points_.push_back(point);
    points_.back().channel_name_index_ = &name_to_index_;
  }
  inline void clear() { points_.clear(); }

 private:
  InnerPointsContainer points_;
  std::vector<ChannelType> channels_;
  std::map<std::string, int> name_to_index_;
};

}  // namespace core
}  // namespace ppcl

#endif  // CORE_POINT_CLOUD_BASE_H_
