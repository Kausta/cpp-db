// Error.cpp
// Created by Caner Korkmaz on 7/9/2017.
// Copyright 2017 Caner Korkmaz
//

#include "Error.h"

#include <sstream>
using namespace cpp_db;

std::string cpp_db::parse_error::form_error_message(const std::string &description) {
  std::stringstream ss;
  ss << "Couldn't parse: " << description;
  return ss.str();
}
std::string cpp_db::parse_error::form_error_message(const std::string &description, const std::string &command) {
  std::stringstream ss;
  ss << "Couldn't parse " << command << ":\n";
  ss << description;
  return ss.str();
}
