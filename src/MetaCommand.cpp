// MetaCommand.cpp
// Created by Caner Korkmaz on 5/9/2017.
// Copyright 2017 Caner Korkmaz
//

#include "MetaCommand.h"

#include <sstream>

using namespace cpp_db;

MetaCommandType cpp_db::parse_meta_command(const std::string &command) {
  if(command == ".exit"){
    return MetaCommandType::EXIT;
  }
  std::stringstream ss;
  ss << "Unrecognized command: '" << command << "'.";
  throw meta_command_parse_error(ss.str(), command);
}
