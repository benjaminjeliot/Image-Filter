// Copyright (c) 2024 Jim Eliot

#ifndef IMAGE_FILTER_INCLUDE_IMGF_SCALAR_H_
#define IMAGE_FILTER_INCLUDE_IMGF_SCALAR_H_

#include <imgf/DataObject.h>

namespace imgf {

class Scalar : public DataObject {
 public:
  ~Scalar() override;
};

inline Scalar::~Scalar() = default;

}  // namespace imgf

#endif  // IMAGE_FILTER_INCLUDE_IMGF_SCALAR_H_
