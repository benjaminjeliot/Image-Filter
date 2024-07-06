// Copyright (c) 2024 Jim Eliot

#include <gtest/gtest.h>

#include <memory>
#include <string>

#include "imgf/InputPort.h"
#include "imgf/OutputPort.h"
#include "imgf/ScalarDouble.h"
#include "imgf/ScalarDoubleNode.h"

TEST(ScalarDoubleNode, ConstructorNoParameters) {
  EXPECT_NO_THROW(imgf::ScalarDoubleNode("node_0"));
}

TEST(ScalarDoubleNode, GetNameAndType) {
  auto node{std::make_shared<imgf::ScalarDoubleNode>("node_0")};
  EXPECT_EQ(node->GetName(), "node_0");
  EXPECT_EQ(node->GetType(), "ScalarDoubleNode");
}

TEST(ScalarDoubleNode, VerifyPorts) {
  auto node{std::make_shared<imgf::ScalarDoubleNode>("node_0")};
  EXPECT_EQ(node->GetNumberOfInputPorts(), 0);
  EXPECT_EQ(node->GetNumberOfOutputPorts(), 1);
  auto output_port{node->GetOutputPort(0)};
  ASSERT_NE(output_port, nullptr);
  EXPECT_EQ(output_port->GetDataTypeName(), "ScalarDouble");
}

TEST(ScalarDoubleNode, VerifyNodeValue) {
  constexpr double node_value{7.5};
  auto node{std::make_shared<imgf::ScalarDoubleNode>("node_0", node_value)};
  auto output_port{node->GetOutputPort(0)};
  ASSERT_NE(output_port, nullptr);
  auto output_object{output_port->GetDataObject()};
  ASSERT_NE(output_object, nullptr);
  auto double_object{
      std::dynamic_pointer_cast<imgf::ScalarDouble>(output_object)};
  ASSERT_NE(double_object, nullptr);
  EXPECT_DOUBLE_EQ(double_object->GetValue(), node_value);
}
