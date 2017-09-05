// ParseError.h
// Created by Caner Korkmaz on 5/9/2017.
// Copyright 2017 Caner Korkmaz
//

#ifndef CPP_DB_PARSEERROR_H
#define CPP_DB_PARSEERROR_H

#include <stdexcept>
#include <utility>

namespace cpp_db{

class parse_error : public std::runtime_error{
 public:
  parse_error(const std::string &description, std::string command)
      : runtime_error(description)
      , command_(std::move(command))
  {}

  const std::string& command() const { return command_; };
 private:
  std::string command_;
};

}

#endif //CPP_DB_PARSEERROR_H
