// Copyright (c) 2024 Jim Eliot

#include "imgf/OutputPort.h"

#include <boost/log/trivial.hpp>

namespace imgf {

OutputPort::~OutputPort() {
  BOOST_LOG_TRIVIAL(trace) << "OutputPort::~OutputPort()";
}

}  // namespace imgf
