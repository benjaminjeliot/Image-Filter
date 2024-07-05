// Copyright (c) 2024 Jim Eliot

#include "imgf/ScalarDoubleNode.h"

#include <boost/log/trivial.hpp>
#include <memory>

#include "imgf/OutputPortTemplate.h"
#include "imgf/ScalarDouble.h"
#include "imgf/ScalarDoubleOutputPort.h"

namespace imgf {

ScalarDoubleNode::~ScalarDoubleNode() {
  BOOST_LOG_TRIVIAL(trace) << "ScalarDoubleNode::~ScalarDoubleNode()";
}

ScalarDoubleNode::ScalarDoubleNode() {
  BOOST_LOG_TRIVIAL(trace) << "ScalarDoubleNode::ScalarDoubleNode()";

  // Initialize ports
  output_port_0_ = std::make_shared<imgf::ScalarDoubleOutputPort>();

  // Initialize node data
  data_object_ = std::make_shared<imgf::ScalarDouble>(0.0);
}

ScalarDoubleNode::ScalarDoubleNode(double value) {
  BOOST_LOG_TRIVIAL(trace) << "ScalarDoubleNode::ScalarDoubleNode()";

  // Initialize ports
  output_port_0_ = std::make_shared<imgf::ScalarDoubleOutputPort>();

  // Initialize node data
  data_object_ = std::make_shared<imgf::ScalarDouble>(value);
}

auto ScalarDoubleNode::GetNumberOfInputPorts() const -> int32_t {
  BOOST_LOG_TRIVIAL(trace) << "ScalarDoubleNode::GetNumberOfInputPorts()";

  return INT32_C(0);
}

auto ScalarDoubleNode::GetNumberOfOutputPorts() const -> int32_t {
  BOOST_LOG_TRIVIAL(trace) << "ScalarDoubleNode::GetNumberOfOutputPorts()";

  return INT32_C(1);
}

auto ScalarDoubleNode::GetInputPort(int32_t index)
    -> std::shared_ptr<imgf::InputPort> {
  BOOST_LOG_TRIVIAL(trace) << "ScalarDoubleNode::GetInputPort()";

  // No input ports
  return nullptr;
}

auto ScalarDoubleNode::GetOutputPort(int32_t index)
    -> std::shared_ptr<imgf::OutputPort> {
  BOOST_LOG_TRIVIAL(trace) << "ScalarDoubleNode::GetOutputPort()";

  if (index == 0) {
    // return output_port_0_;
    BOOST_LOG_TRIVIAL(trace) << "returning output_port_0_";
    output_port_0_->RegisterParentNode(weak_from_this());
    return std::dynamic_pointer_cast<imgf::OutputPort>(output_port_0_);
  }

  return nullptr;
}

auto ScalarDoubleNode::Execute() -> void {
  BOOST_LOG_TRIVIAL(trace) << "ScalarDoubleNode::Execute()";

  output_port_0_->SetDataObject(data_object_);
}

}  // namespace imgf
