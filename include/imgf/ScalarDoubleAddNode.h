// Copyright (c) 2024 Jim Eliot

#ifndef IMAGE_FILTER_INCLUDE_IMGF_SCALARDOUBLEADDNODE_H_
#define IMAGE_FILTER_INCLUDE_IMGF_SCALARDOUBLEADDNODE_H_

#include <imgf/Node.h>
#include <imgf/ScalarDoubleInputPort.h>
#include <imgf/ScalarDoubleOutputPort.h>

#include <cstdint>
#include <memory>

namespace imgf {

// Forward declarations
class ScalarDouble;
class InputPort;
class OutputPort;

class ScalarDoubleAddNode : public Node {
 public:
  //! \brief Destructor.
  ~ScalarDoubleAddNode() override;

  //! brief Constructor.
  //!
  //! \param name The name of the node.
  ScalarDoubleAddNode(std::string name);

  //! \brief Constructor.
  //!
  //! \param name The name of the node.
  //! \param value The value of the scalar.
  explicit ScalarDoubleAddNode(std::string name, double value);

  auto GetType() const -> std::string override;

  auto GetNumberOfInputPorts() const -> std::int32_t override;

  auto GetNumberOfOutputPorts() const -> std::int32_t override;

  auto GetInputPort(std::int32_t index)
      -> std::shared_ptr<imgf::InputPort> override;

  auto GetOutputPort(std::int32_t index)
      -> std::shared_ptr<imgf::OutputPort> override;

  auto Execute() -> void override;

 private:
  ScalarDoubleAddNode() = delete;

  static const std::string type_name_;
  std::shared_ptr<imgf::ScalarDoubleInputPort> input_port_0_{nullptr};
  std::shared_ptr<imgf::ScalarDoubleInputPort> input_port_1_{nullptr};
  std::shared_ptr<imgf::ScalarDoubleOutputPort> output_port_0_{nullptr};
  std::shared_ptr<imgf::ScalarDouble> data_object_{nullptr};
};

}  // namespace imgf

#endif  // IMAGE_FILTER_INCLUDE_IMGF_SCALARDOUBLEADDNODE_H_
