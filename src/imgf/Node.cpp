// Copyright (c) 2024 Jim Eliot

#include "imgf/Node.h"

#include <boost/log/trivial.hpp>

namespace imgf {

Node::~Node() { BOOST_LOG_TRIVIAL(trace) << "Node::~Node()"; }

Node::Node(std::string name) {
  BOOST_LOG_TRIVIAL(trace) << "Node::Node()";

  name_ = name;
}

auto Node::GetName() const -> std::string {
  BOOST_LOG_TRIVIAL(trace) << "Node::GetName()";

  return name_;
}

}  // namespace imgf
