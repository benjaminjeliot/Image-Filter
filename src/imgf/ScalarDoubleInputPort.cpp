// Copyright (c) 2024 Jim Eliot

#include "imgf/ScalarDoubleInputPort.h"

#include <boost/log/trivial.hpp>

namespace imgf {

template <>
auto ScalarDoubleInputPort::GetDataTypeName() const -> std::string {
  BOOST_LOG_TRIVIAL(trace) << "ScalarDoubleInputPort::GetDataTypeName()";

  return "ScalarDouble";
}

}  // namespace imgf
