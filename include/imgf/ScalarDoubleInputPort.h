// Copyright (c) 2024 Jim Eliot

#ifndef IMAGE_FILTER_INCLUDE_IMGF_SCALARDOUBLEINPUTPORT_H_
#define IMAGE_FILTER_INCLUDE_IMGF_SCALARDOUBLEINPUTPORT_H_

#include <imgf/InputPortTemplate.h>

#include <memory>
#include <string>

namespace imgf {

// Forward declarations
class ScalarDouble;

using ScalarDoubleInputPort = imgf::InputPortTemplate<imgf::ScalarDouble>;

template <>
auto ScalarDoubleInputPort::GetDataTypeName() const -> std::string;

}  // namespace imgf

#endif  // IMAGE_FILTER_INCLUDE_IMGF_SCALARDOUBLEINPUTPORT_H_
