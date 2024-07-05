// Copyright (c) 2024 Jim Eliot

#include "imgf/ScalarDouble.h"

#include <boost/log/trivial.hpp>

namespace imgf {

ScalarDouble::~ScalarDouble() {
  BOOST_LOG_TRIVIAL(trace) << "ScalarDouble::~ScalarDouble()";
}

ScalarDouble::ScalarDouble(double value) : value_(value) {
  BOOST_LOG_TRIVIAL(trace) << "ScalarDouble::ScalarDouble()";
}

auto ScalarDouble::GetDataTypeName() const -> std::string {
  BOOST_LOG_TRIVIAL(trace) << "ScalarDouble::GetDataTypeName()";

  return "ScalarDouble";
}

auto ScalarDouble::GetValue() const -> double {
  BOOST_LOG_TRIVIAL(trace) << "ScalarDouble::GetValue()";
  return value_;
}

}  // namespace imgf
