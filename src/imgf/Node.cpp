// Copyright (c) 2024 Jim Eliot

#include "imgf/Node.h"

#include <boost/log/trivial.hpp>

namespace imgf {

Node::~Node() { BOOST_LOG_TRIVIAL(trace) << "Node::~Node()"; }

}  // namespace imgf
