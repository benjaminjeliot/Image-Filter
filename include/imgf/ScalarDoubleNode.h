// Copyright (c) 2024 Jim Eliot

#ifndef IMAGE_FILTER_INCLUDE_IMGF_SCALARDOUBLENODE_H_
#define IMAGE_FILTER_INCLUDE_IMGF_SCALARDOUBLENODE_H_

#include <imgf/Node.h>
#include <imgf/ScalarDoubleOutputPort.h>

#include <cstdint>
#include <memory>

namespace imgf {

// Forward declarations
class InputPort;
class OutputPort;
class ScalarDouble;

class ScalarDoubleNode : public Node {
 public:
  //! \brief Destructor.
  ~ScalarDoubleNode() override;

  //! brief Constructor.
  ScalarDoubleNode();

  //! \brief Constructor.
  //!
  //! \param value The value of the scalar.
  explicit ScalarDoubleNode(double value);

  auto GetNumberOfInputPorts() const -> int32_t override;

  auto GetNumberOfOutputPorts() const -> int32_t override;

  auto GetInputPort(int32_t index) -> std::shared_ptr<imgf::InputPort> override;

  auto GetOutputPort(int32_t index)
      -> std::shared_ptr<imgf::OutputPort> override;

  auto Execute() -> void override;

 private:
  std::shared_ptr<imgf::ScalarDoubleOutputPort> output_port_0_{nullptr};
  std::shared_ptr<imgf::ScalarDouble> data_object_{nullptr};
};

}  // namespace imgf

#endif  // IMAGE_FILTER_INCLUDE_IMGF_SCALARDOUBLENODE_H_
