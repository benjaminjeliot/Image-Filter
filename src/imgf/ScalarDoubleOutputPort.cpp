// Copyright (c) 2024 Jim Eliot

#include "imgf/ScalarDoubleOutputPort.h"

#include <string>

namespace imgf {

template <>
auto ScalarDoubleOutputPort::GetDataTypeName() const -> std::string {
  return "ScalarDouble";
}

}  // namespace imgf
