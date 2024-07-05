// Copyright (c) 2024 Jim Eliot

#ifndef IMAGE_FILTER_INCLUDE_IMGF_DATAOBJECT_H_
#define IMAGE_FILTER_INCLUDE_IMGF_DATAOBJECT_H_

#include <string>

namespace imgf {

class DataObject {
 public:
  virtual ~DataObject() = 0;

  virtual auto GetDataTypeName() const -> std::string = 0;
};

inline DataObject::~DataObject() = default;

}  // namespace imgf

#endif  // IMAGE_FILTER_INCLUDE_IMGF_DATAOBJECT_H_
