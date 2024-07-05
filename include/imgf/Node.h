// Copyright (c) 2024 Jim Eliot

#ifndef IMAGE_FILTER_INCLUDE_IMGF_NODE_H_
#define IMAGE_FILTER_INCLUDE_IMGF_NODE_H_

#include <cstdint>
#include <memory>

namespace imgf {

class InputPort;
class OutputPort;

class Node : public std::enable_shared_from_this<Node> {
 public:
  //! \brief Destructor.
  virtual ~Node() = 0;

  //! \brief Get the number of input ports.
  //! \return The number of input ports.
  virtual auto GetNumberOfInputPorts() const -> int32_t = 0;

  //! \brief Get the number of output ports.
  //! \return The number of output ports.
  virtual auto GetNumberOfOutputPorts() const -> int32_t = 0;

  //! \brief Get the input port.
  //! \param index The index of the input port.
  //! \return The input port.
  virtual auto GetInputPort(int32_t index)
      -> std::shared_ptr<imgf::InputPort> = 0;

  //! \brief Get the output port.
  //! \param index The index of the output port.
  //! \return The output port.
  virtual auto GetOutputPort(int32_t index)
      -> std::shared_ptr<imgf::OutputPort> = 0;

  virtual auto Execute() -> void = 0;
};

}  // namespace imgf

#endif  // IMAGE_FILTER_INCLUDE_IMGF_NODE_H_
