// Copyright (c) 2024 Jim Eliot

#include "imgf/ScalarDoubleNode.h"

#include <boost/log/trivial.hpp>
#include <memory>

#include "imgf/OutputPortTemplate.h"
#include "imgf/ScalarDouble.h"
#include "imgf/ScalarDoubleOutputPort.h"

namespace imgf {

const std::string ScalarDoubleNode::type_name_{"ScalarDoubleNode"};

ScalarDoubleNode::~ScalarDoubleNode() {
  BOOST_LOG_TRIVIAL(trace) << "ScalarDoubleNode::~ScalarDoubleNode()";
}

ScalarDoubleNode::ScalarDoubleNode(std::string name) : Node(name) {
  BOOST_LOG_TRIVIAL(trace) << "ScalarDoubleNode::ScalarDoubleNode()";

  // Initialize ports
  output_port_0_ = std::make_shared<imgf::ScalarDoubleOutputPort>();

  // Initialize node data
  data_object_ = std::make_shared<imgf::ScalarDouble>(0.0);
}

ScalarDoubleNode::ScalarDoubleNode(std::string name, double value)
    : Node(name) {
  BOOST_LOG_TRIVIAL(trace) << "ScalarDoubleNode::ScalarDoubleNode()";

  // Initialize ports
  output_port_0_ = std::make_shared<imgf::ScalarDoubleOutputPort>();

  // Initialize node data
  data_object_ = std::make_shared<imgf::ScalarDouble>(value);
}

auto ScalarDoubleNode::GetType() const -> std::string {
  BOOST_LOG_TRIVIAL(trace) << "ScalarDoubleNode::GetType()";

  return type_name_;
}

auto ScalarDoubleNode::GetNumberOfInputPorts() const -> std::int32_t {
  BOOST_LOG_TRIVIAL(trace) << "ScalarDoubleNode::GetNumberOfInputPorts()";

  return INT32_C(0);
}

auto ScalarDoubleNode::GetNumberOfOutputPorts() const -> std::int32_t {
  BOOST_LOG_TRIVIAL(trace) << "ScalarDoubleNode::GetNumberOfOutputPorts()";

  return INT32_C(1);
}

auto ScalarDoubleNode::GetInputPort(std::int32_t index)
    -> std::shared_ptr<imgf::InputPort> {
  BOOST_LOG_TRIVIAL(trace) << "ScalarDoubleNode::GetInputPort()";

  // No input ports
  return nullptr;
}

auto ScalarDoubleNode::GetOutputPort(std::int32_t index)
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
