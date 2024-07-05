// Copyright (c) 2024 Jim Eliot

#ifndef IMAGE_FILTER_INCLUDE_IMGF_INPUTPORT_H_
#define IMAGE_FILTER_INCLUDE_IMGF_INPUTPORT_H_

#include <memory>
#include <string>

namespace imgf {

class DataObject;
class OutputPort;

class InputPort {
 public:
  //! \brief Destructor.
  virtual ~InputPort() = 0;

  //! \brief Get the data type name of the input port.
  //!
  //! \return The data type name of the input port.
  virtual auto GetDataTypeName() const -> std::string = 0;

  //! \brief Get the data object from the input port.
  //!
  //! \return The data object from the input port.
  virtual auto GetDataObject() -> std::shared_ptr<imgf::DataObject> = 0;

  //! \brief Attach an output port to the input port.
  //!
  //! \param port The output port to attach.
  virtual auto Attach(std::shared_ptr<imgf::OutputPort> port) -> void = 0;
};

}  // namespace imgf

#endif  // IMAGE_FILTER_INCLUDE_IMGF_INPUTPORT_H_
