// Copyright (c) 2024 Jim Eliot

#ifndef IMAGE_FILTER_INCLUDE_IMGF_SCALARDOUBLE_H_
#define IMAGE_FILTER_INCLUDE_IMGF_SCALARDOUBLE_H_

#include <imgf/Scalar.h>

#include <string>

namespace imgf {

class ScalarDouble : public Scalar {
 public:
  ~ScalarDouble() override;

  //! \brief Constructor.
  //!
  //! \param value The value of the scalar.
  explicit ScalarDouble(double value);

  auto GetDataTypeName() const -> std::string override;

  auto GetValue() const -> double;

 private:
  double value_{0.0};
};

}  // namespace imgf

#endif  // IMAGE_FILTER_INCLUDE_IMGF_SCALARDOUBLE_H_
