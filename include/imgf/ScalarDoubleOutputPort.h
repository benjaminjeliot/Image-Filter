// Copyright (c) 2024 Jim Eliot

#ifndef IMAGE_FILTER_INCLUDE_IMGF_SCALARDOUBLEOUTPUTPORT_H_
#define IMAGE_FILTER_INCLUDE_IMGF_SCALARDOUBLEOUTPUTPORT_H_

#include <imgf/OutputPortTemplate.h>
#include <imgf/ScalarDouble.h>

#include <memory>
#include <string>

namespace imgf {

class ScalarDouble;

using ScalarDoubleOutputPort = imgf::OutputPortTemplate<imgf::ScalarDouble>;

template <>
auto ScalarDoubleOutputPort::GetDataTypeName() const -> std::string;

}  // namespace imgf

#endif  // IMAGE_FILTER_INCLUDE_IMGF_SCALARDOUBLEOUTPUTPORT_H_
