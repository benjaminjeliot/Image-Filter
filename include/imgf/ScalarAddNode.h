// Copyright (c) 2024 Jim Eliot

#ifndef IMAGE_FILTER_INCLUDE_IMGF_SCALARADDNODE_H_
#define IMAGE_FILTER_INCLUDE_IMGF_SCALARADDNODE_H_

#include <imgf/InputPort.h>
#include <imgf/Node.h>
#include <imgf/OutputPort.h>
#include <imgf/ScalarDouble.h>
#include <imgf/ScalarDoubleInputPort.h>
#include <imgf/ScalarDoubleNode.h>

#include <memory>

namespace imgf {

class ScalarAddNode : public Node {
 public:
  //! \brief Destructor.
  ~ScalarAddNode() override;

  //! \brief Constructor.`
  ScalarAddNode();

  //! brief Constructor.
  //!
  //! \param port_0 The first input port.
  //! \param port_1 The second input port.
  ScalarAddNode(std::shared_ptr<imgf::ScalarDoubleInputPort> port_0,
                std::shared_ptr<imgf::ScalarDoubleInputPort> port_1);

  //! \brief Constructor.
  //!
  //! \param node_0 The first input port.
  //! \param node_1 The second input port.
  ScalarAddNode(std::shared_ptr<imgf::ScalarDoubleNode> node_0,
                std::shared_ptr<imgf::ScalarDoubleNode> node_1);

 private:
  std::shared_ptr<imgf::InputPort> input_port_0{nullptr};
  std::shared_ptr<imgf::InputPort> input_port_1{nullptr};
  std::shared_ptr<imgf::OutputPort> output_port_0{nullptr};
};

}  // namespace imgf

#endif  // IMAGE_FILTER_INCLUDE_IMGF_SCALARADDNODE_H_
