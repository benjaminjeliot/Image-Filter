// Copyright (c) 2024 Jim Eliot

#include <boost/log/core.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/trivial.hpp>
#include <cstddef>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "imgf/InputPort.h"
#include "imgf/Node.h"
#include "imgf/OutputPort.h"
#include "imgf/ScalarDouble.h"
#include "imgf/ScalarDoubleAddNode.h"
#include "imgf/ScalarDoubleNode.h"

auto main(int argc, char *argv[]) -> int {
  std::cout << "app" << std::endl;

  // Set logging level
  boost::log::core::get()->set_filter(boost::log::trivial::severity >=
                                      boost::log::trivial::info);

  std::vector<std::shared_ptr<imgf::Node>> node_list;

  constexpr double value_0{3.4};
  constexpr double value_1{4.5};
  constexpr double value_4{8.2};

  auto node_0{std::make_shared<imgf::ScalarDoubleNode>("node_0", value_0)};
  auto node_1{std::make_shared<imgf::ScalarDoubleNode>("node_1", value_1)};
  auto node_2{std::make_shared<imgf::ScalarDoubleAddNode>("node_2")};
  auto node_3{std::make_shared<imgf::ScalarDoubleNode>("node_3")};
  auto node_4{std::make_shared<imgf::ScalarDoubleNode>("node_4", value_4)};
  auto node_5{std::make_shared<imgf::ScalarDoubleAddNode>("node_5")};
  auto node_6{std::make_shared<imgf::ScalarDoubleAddNode>("node_6")};

  node_2->GetInputPort(0)->Attach(node_0->GetOutputPort(0));
  node_2->GetInputPort(1)->Attach(node_1->GetOutputPort(0));

  node_5->GetInputPort(0)->Attach(node_3->GetOutputPort(0));
  node_5->GetInputPort(1)->Attach(node_4->GetOutputPort(0));

  node_6->GetInputPort(0)->Attach(node_2->GetOutputPort(0));
  node_6->GetInputPort(1)->Attach(node_5->GetOutputPort(0));

  node_list.push_back(std::dynamic_pointer_cast<imgf::Node>(node_0));
  node_list.push_back(std::dynamic_pointer_cast<imgf::Node>(node_1));
  node_list.push_back(std::dynamic_pointer_cast<imgf::Node>(node_2));
  node_list.push_back(std::dynamic_pointer_cast<imgf::Node>(node_3));
  node_list.push_back(std::dynamic_pointer_cast<imgf::Node>(node_4));
  node_list.push_back(std::dynamic_pointer_cast<imgf::Node>(node_5));
  node_list.push_back(std::dynamic_pointer_cast<imgf::Node>(node_6));

  for (auto &node : node_list) {
    std::cout << "Node" << std::endl;
    std::cout << "Name: " << node->GetName() << std::endl;
    std::cout << "Number of input ports: " << node->GetNumberOfInputPorts()
              << std::endl;
    std::cout << "Input ports:" << std::endl;
    for (std::int32_t i{0}; i < node->GetNumberOfInputPorts(); ++i) {
      auto input_port = node->GetInputPort(i);
      std::cout << "Input port " << i
                << " data type name: " << input_port->GetDataTypeName()
                << std::endl;
    }

    std::cout << "Number of output ports: " << node->GetNumberOfOutputPorts()
              << std::endl;
    std::cout << "Output ports:" << std::endl;
    for (std::int32_t i{0}; i < node->GetNumberOfOutputPorts(); ++i) {
      auto output_port = node->GetOutputPort(i);
      std::cout << "Output port " << i
                << " data type name: " << output_port->GetDataTypeName()
                << std::endl;
    }

    std::cout << std::endl;
  }

  return 0;
}
