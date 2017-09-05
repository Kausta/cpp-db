// Statement.h
// Created by Caner Korkmaz on 5/9/2017.
// Copyright 2017 Caner Korkmaz
//

#ifndef CPP_DB_STATEMENT_H
#define CPP_DB_STATEMENT_H

#include <string>
#include <stdexcept>
#include <iostream>
#include <sstream>
#include "Util.h"
#include "ParseError.h"

namespace cpp_db{
class statement_parse_error : public parse_error{
 public:
  statement_parse_error(const std::string &description, const std::string &command)
      : parse_error(description, command)
  {}
};

class Statement{
 public:
  enum class Type{
    INSERT,
    SELECT
  };
 public:
  explicit Statement(std::string command)
      : command_(std::move(command))
      , type_(parse_command(command_))
  { }

  void execute() const {
    switch(type_){
      case Type::INSERT:
        std::cout << "Insert stmt\n";
        break;
      case Type::SELECT:
        std::cout << "Select stmt\n";
        break;
    }
  }

  const std::string& command() const { return command_ ;}
  Type type() const { return type_; }
 private:
  Type parse_command(const std::string& command){
    if(util::starts_with(command, "insert")){
      return Type::INSERT;
    }
    if(util::starts_with(command, "select")){
      return Type::SELECT;
    }
    std::stringstream ss;
    ss << "Unrecognized keyword at start of '" << command << "'.";
    throw statement_parse_error(ss.str(), command);
  }

  std::string command_;
  Type type_;
};
}

#endif //CPP_DB_STATEMENT_H
