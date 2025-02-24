// Copyright (c) 2024 Jim Eliot

#include <gtest/gtest.h>

#include <memory>
#include <string>

#include "imgf/InputPort.h"
#include "imgf/OutputPort.h"
#include "imgf/ScalarDouble.h"
#include "imgf/ScalarDoubleAddNode.h"
#include "imgf/ScalarDoubleNode.h"

TEST(ScalarDoubleAddNode, ConstructorNoParameters) {
  EXPECT_NO_THROW(imgf::ScalarDoubleAddNode("node_0"));
}

TEST(ScalarDoubleAddNode, GetNameAndType) {
  auto node{std::make_shared<imgf::ScalarDoubleAddNode>("node_0")};
  EXPECT_EQ(node->GetName(), "node_0");
  EXPECT_EQ(node->GetType(), "ScalarDoubleAddNode");
}

TEST(ScalarDoubleAddNode, VerifyPorts) {
  auto node{std::make_shared<imgf::ScalarDoubleAddNode>("node_0")};
  EXPECT_EQ(node->GetNumberOfInputPorts(), 2);
  EXPECT_EQ(node->GetNumberOfOutputPorts(), 1);
  auto input_port_0{node->GetInputPort(0)};
  auto input_port_1{node->GetInputPort(1)};
  auto output_port{node->GetOutputPort(0)};
  ASSERT_NE(input_port_0, nullptr);
  ASSERT_NE(input_port_1, nullptr);
  ASSERT_NE(output_port, nullptr);
  EXPECT_EQ(input_port_0->GetDataTypeName(), "ScalarDouble");
  EXPECT_EQ(input_port_1->GetDataTypeName(), "ScalarDouble");
  EXPECT_EQ(output_port->GetDataTypeName(), "ScalarDouble");
}

TEST(ScalarDoubleAddNode, VerifyAddition) {
  constexpr double value_0{7.5};
  constexpr double value_1{14.1};
  constexpr double expected_value{21.6};
  auto node_0{std::make_shared<imgf::ScalarDoubleNode>("node_0", value_0)};
  auto node_1{std::make_shared<imgf::ScalarDoubleNode>("node_1", value_1)};
  auto add_node{std::make_shared<imgf::ScalarDoubleAddNode>("add_node")};
  add_node->GetInputPort(0)->Attach(node_0->GetOutputPort(0));
  add_node->GetInputPort(1)->Attach(node_1->GetOutputPort(0));
  auto output_port_0{add_node->GetOutputPort(0)};
  ASSERT_NE(output_port_0, nullptr);
  auto output_object{output_port_0->GetDataObject()};
  ASSERT_NE(output_object, nullptr);
  auto double_object{
      std::dynamic_pointer_cast<imgf::ScalarDouble>(output_object)};
  ASSERT_NE(double_object, nullptr);
  EXPECT_DOUBLE_EQ(double_object->GetValue(), expected_value);
}
