// Copyright (c) 2024 Jim Eliot

#include "imgf/InputPort.h"

#include <boost/log/trivial.hpp>

namespace imgf {

InputPort::~InputPort() {
  BOOST_LOG_TRIVIAL(trace) << "InputPort::~InputPort()";
}

}  // namespace imgf
