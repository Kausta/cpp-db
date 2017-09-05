// MetaCommand.h
// Created by Caner Korkmaz on 5/9/2017.
// Copyright 2017 Caner Korkmaz
//

#ifndef CPP_DB_METACOMMAND_H
#define CPP_DB_METACOMMAND_H

#include <string>
#include "Error.h"

namespace cpp_db{
class meta_command_parse_error : public parse_error{
 public:
  meta_command_parse_error(const std::string &description, std::string command)
      : parse_error(description, std::move(command))
  {}
 public:

};

enum class MetaCommandType{
  EXIT
};

MetaCommandType parse_meta_command(const std::string& command);
}

#endif //CPP_DB_METACOMMAND_H
