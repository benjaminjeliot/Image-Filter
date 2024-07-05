// Copyright (c) 2024 Jim Eliot

#include <gtest/gtest.h>

#include <memory>

#include "imgf/OutputPort.h"
#include "imgf/ScalarDoubleOutputPort.h"

TEST(OutputPort, GetDataTypeName) {
  std::shared_ptr<imgf::OutputPort> output_port{
      std::make_shared<imgf::ScalarDoubleOutputPort>()};

  EXPECT_EQ(output_port->GetDataTypeName(), "ScalarDouble");
}
