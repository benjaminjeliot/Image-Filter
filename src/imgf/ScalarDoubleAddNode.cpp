// Copyright (c) 2024 Jim Eliot

#include "imgf/ScalarDoubleAddNode.h"

#include <boost/log/trivial.hpp>
#include <memory>

#include "imgf/InputPortTemplate.h"
#include "imgf/OutputPortTemplate.h"
#include "imgf/ScalarDouble.h"
#include "imgf/ScalarDoubleInputPort.h"
#include "imgf/ScalarDoubleOutputPort.h"

namespace imgf {

ScalarDoubleAddNode::~ScalarDoubleAddNode() {
  BOOST_LOG_TRIVIAL(trace) << "ScalarDoubleAddNode::~ScalarDoubleAddNode()";
}

ScalarDoubleAddNode::ScalarDoubleAddNode() {
  BOOST_LOG_TRIVIAL(trace) << "ScalarDoubleAddNode::ScalarDoubleAddNode()";

  // Initialize ports
  input_port_0_ = std::make_shared<imgf::ScalarDoubleInputPort>();
  input_port_1_ = std::make_shared<imgf::ScalarDoubleInputPort>();
  output_port_0_ = std::make_shared<imgf::ScalarDoubleOutputPort>();

  // Initialize node data
  data_object_ = std::make_shared<imgf::ScalarDouble>(0.0);
}

auto ScalarDoubleAddNode::GetNumberOfInputPorts() const -> int32_t {
  BOOST_LOG_TRIVIAL(trace) << "ScalarDoubleAddNode::GetNumberOfInputPorts()";

  return INT32_C(2);
}

auto ScalarDoubleAddNode::GetNumberOfOutputPorts() const -> int32_t {
  BOOST_LOG_TRIVIAL(trace) << "ScalarDoubleAddNode::GetNumberOfOutputPorts()";

  return INT32_C(1);
}

auto ScalarDoubleAddNode::GetInputPort(int32_t index)
    -> std::shared_ptr<imgf::InputPort> {
  BOOST_LOG_TRIVIAL(trace) << "ScalarDoubleAddNode::GetInputPort()";

  if (index == 0) {
    // return input_port_0_;
    BOOST_LOG_TRIVIAL(trace) << "returning input_port_0_";
    return std::dynamic_pointer_cast<imgf::InputPort>(input_port_0_);
  }

  if (index == 1) {
    // return input_port_1_;
    BOOST_LOG_TRIVIAL(trace) << "returning input_port_1_";
    return std::dynamic_pointer_cast<imgf::InputPort>(input_port_1_);
  }

  // No input ports
  return nullptr;
}

auto ScalarDoubleAddNode::GetOutputPort(int32_t index)
    -> std::shared_ptr<imgf::OutputPort> {
  BOOST_LOG_TRIVIAL(trace) << "ScalarDoubleAddNode::GetOutputPort()";

  if (index == 0) {
    // return output_port_0_;
    BOOST_LOG_TRIVIAL(trace) << "returning output_port_0_";
    output_port_0_->RegisterParentNode(weak_from_this());
    return std::dynamic_pointer_cast<imgf::OutputPort>(output_port_0_);
  }

  return nullptr;
}

auto ScalarDoubleAddNode::Execute() -> void {
  BOOST_LOG_TRIVIAL(trace) << "ScalarDoubleAddNode::Execute()";

  auto data_object_0{input_port_0_->GetDataObject()};
  auto data_object_1{input_port_1_->GetDataObject()};

  if (data_object_0 != nullptr && data_object_1 != nullptr) {
    auto double_data_object_0{
        std::dynamic_pointer_cast<imgf::ScalarDouble>(data_object_0)};
    auto double_data_object_1{
        std::dynamic_pointer_cast<imgf::ScalarDouble>(data_object_1)};

    if (double_data_object_0 != nullptr && double_data_object_1 != nullptr) {
      data_object_ = std::make_shared<imgf::ScalarDouble>(
          double_data_object_0->GetValue() + double_data_object_1->GetValue());
    }
    output_port_0_->SetDataObject(data_object_);
  }
}

}  // namespace imgf
