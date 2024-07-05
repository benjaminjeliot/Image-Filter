// Copyright (c) 2024 Jim Eliot

#ifndef IMAGE_FILTER_INCLUDE_IMGF_OUTPUTPORTEMPLATE_H_
#define IMAGE_FILTER_INCLUDE_IMGF_OUTPUTPORTEMPLATE_H_

#include <imgf/Node.h>
#include <imgf/OutputPort.h>

#include <boost/log/trivial.hpp>
#include <memory>

namespace imgf {

template <class T>
class OutputPortTemplate : public imgf::OutputPort {
 public:
  //! \brief Destructor.
  ~OutputPortTemplate() override;

  auto GetDataTypeName() const -> std::string override;

  auto GetDataObject() -> std::shared_ptr<imgf::DataObject> override;

  auto SetDataObject(std::shared_ptr<imgf::DataObject> data_object)
      -> void override;

  auto RegisterParentNode(std::weak_ptr<imgf::Node> node) -> void override;

 private:
  std::shared_ptr<T> data_object_{nullptr};
};

template <class T>
OutputPortTemplate<T>::~OutputPortTemplate() {
  BOOST_LOG_TRIVIAL(trace) << "OutputPortTemplate::~OutputPortTemplate()";
}

template <class T>
auto OutputPortTemplate<T>::GetDataTypeName() const -> std::string {
  return typeid(T).name();
}

template <class T>
auto OutputPortTemplate<T>::GetDataObject()
    -> std::shared_ptr<imgf::DataObject> {
  // Alert the parent node that data is requested
  BOOST_LOG_TRIVIAL(trace) << "OutputPortTemplate::GetDataObject()";
  if (auto node = node_.lock()) {
    BOOST_LOG_TRIVIAL(trace) << "Lock acquired";
    node->Execute();
  } else {
    BOOST_LOG_TRIVIAL(error) << "Failed to acquire lock";
  }

  return data_object_;
}

template <class T>
auto OutputPortTemplate<T>::SetDataObject(
    std::shared_ptr<imgf::DataObject> data_object) -> void {
  BOOST_LOG_TRIVIAL(trace) << "OutputPortTemplate::SetDataObject()";
  data_object_ = std::dynamic_pointer_cast<T>(data_object);
}

template <class T>
auto OutputPortTemplate<T>::RegisterParentNode(std::weak_ptr<imgf::Node> node)
    -> void {
  BOOST_LOG_TRIVIAL(trace) << "OutputPortTemplate::RegisterParentNode()";
  node_ = node;
}

}  // namespace imgf

#endif  // IMAGE_FILTER_INCLUDE_IMGF_OUTPUTPORTEMPLATE_H_
