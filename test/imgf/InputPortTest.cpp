// Copyright (c) 2024 Jim Eliot

#include <gtest/gtest.h>

#include <memory>

#include "imgf/InputPort.h"
#include "imgf/ScalarDoubleInputPort.h"

TEST(InputPort, GetDataTypeName) {
  std::shared_ptr<imgf::InputPort> input_port{
      std::make_shared<imgf::ScalarDoubleInputPort>()};

  EXPECT_EQ(input_port->GetDataTypeName(), "ScalarDouble");
}
