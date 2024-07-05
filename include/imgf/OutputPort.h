// Copyright (c) 2024 Jim Eliot

#ifndef IMAGE_FILTER_INCLUDE_IMGF_OUTPUTPORT_H_
#define IMAGE_FILTER_INCLUDE_IMGF_OUTPUTPORT_H_

#include <memory>
#include <string>

namespace imgf {

// Forward declarations
class DataObject;
class Node;

class OutputPort {
 public:
  //! \brief Destructor.
  virtual ~OutputPort() = 0;

  //! \brief Get the data type name of the input port.
  //!
  //! \return The data type name of the input port.
  virtual auto GetDataTypeName() const -> std::string = 0;

  //! \brief Get the data object of the output port.
  //!
  //! \return The data object of the output port.
  virtual auto GetDataObject() -> std::shared_ptr<imgf::DataObject> = 0;

  //! \brief Set the data object of the output port.
  //!
  //! \param data_object The data object of the output port.
  virtual auto SetDataObject(std::shared_ptr<imgf::DataObject> data_object)
      -> void = 0;

  virtual auto RegisterParentNode(std::weak_ptr<imgf::Node> node) -> void = 0;

 protected:
  std::weak_ptr<imgf::Node> node_;
};

}  // namespace imgf

#endif  // IMAGE_FILTER_INCLUDE_IMGF_OUTPUTPORT_H_
