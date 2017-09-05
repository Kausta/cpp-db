// MetaCommand.h
// Created by Caner Korkmaz on 5/9/2017.
// Copyright 2017 Caner Korkmaz
//

#ifndef CPP_DB_METACOMMAND_H
#define CPP_DB_METACOMMAND_H

#include <string>
#include <stdexcept>
#include <sstream>
#include "ParseError.h"

namespace cpp_db{
class meta_command_parse_error : public parse_error{
 public:
  meta_command_parse_error(const std::string &description, const std::string &command)
      : parse_error(description, command)
  {}
 public:

};

enum class MetaCommandType{
  EXIT
};

MetaCommandType parse_meta_command(const std::string& command){
  if(command == ".exit"){
    return MetaCommandType::EXIT;
  }
  std::stringstream ss;
  ss << "Unrecognized command: '" << command << "'.";
  throw meta_command_parse_error(ss.str(), command);
}
}

#endif //CPP_DB_METACOMMAND_H
