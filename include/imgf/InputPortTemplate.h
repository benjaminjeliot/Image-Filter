// Copyright (c) 2024 Jim Eliot

#ifndef IMAGE_FILTER_INCLUDE_IMGF_INPUTPORTTEMPLATE_H_
#define IMAGE_FILTER_INCLUDE_IMGF_INPUTPORTTEMPLATE_H_

#include <imgf/InputPort.h>
#include <imgf/OutputPort.h>

#include <string>

namespace imgf {

template <class T>
class InputPortTemplate : public imgf::InputPort {
 public:
  //! \brief Destructor.
  ~InputPortTemplate() override;

  auto GetDataTypeName() const -> std::string override;

  auto GetDataObject() -> std::shared_ptr<imgf::DataObject> override;

  auto Attach(std::shared_ptr<imgf::OutputPort> port) -> void override;

 private:
  std::shared_ptr<imgf::OutputPort> output_port_{nullptr};
};

template <class T>
InputPortTemplate<T>::~InputPortTemplate() = default;

template <class T>
auto InputPortTemplate<T>::GetDataTypeName() const -> std::string {
  return typeid(T).name();
}

template <class T>
auto InputPortTemplate<T>::GetDataObject()
    -> std::shared_ptr<imgf::DataObject> {
  if (output_port_ != nullptr) {
    return output_port_->GetDataObject();
  }

  return nullptr;
}

template <class T>
auto InputPortTemplate<T>::Attach(std::shared_ptr<imgf::OutputPort> port)
    -> void {
  output_port_ = port;
}

}  // namespace imgf

#endif  // IMAGE_FILTER_INCLUDE_IMGF_INPUTPORTTEMPLATE_H_
