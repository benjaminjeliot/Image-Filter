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
  //!
  //! \param name The name of the node.
  ScalarDoubleNode(std::string name);

  //! \brief Constructor.
  //!
  //! \param name The name of the node.
  //! \param value The value of the scalar.
  explicit ScalarDoubleNode(std::string name, double value);

  auto GetType() const -> std::string override;

  auto GetNumberOfInputPorts() const -> std::int32_t override;

  auto GetNumberOfOutputPorts() const -> std::int32_t override;

  auto GetInputPort(std::int32_t index)
      -> std::shared_ptr<imgf::InputPort> override;

  auto GetOutputPort(std::int32_t index)
      -> std::shared_ptr<imgf::OutputPort> override;

  auto Execute() -> void override;

 private:
  static const std::string type_name_;
  std::shared_ptr<imgf::ScalarDoubleOutputPort> output_port_0_{nullptr};
  std::shared_ptr<imgf::ScalarDouble> data_object_{nullptr};
};

}  // namespace imgf

#endif  // IMAGE_FILTER_INCLUDE_IMGF_SCALARDOUBLENODE_H_
