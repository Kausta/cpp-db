// MetaCommand.cpp
// Created by Caner Korkmaz on 5/9/2017.
// Copyright 2017 Caner Korkmaz
//

#include "MetaCommand.h"

#include <sstream>

using namespace cpp_db;

bool ::cpp_db::is_meta_command(const std::string &command) {
  return command.length() > 0 && command[0] == '.';
}

MetaCommandType cpp_db::parse_meta_command(const std::string &command) {
  if(!is_meta_command(command)){
    throw not_meta_command_error("Given command is not a meta command, should have been checked before parsing!");
  }
  if (command==".exit") {
    return MetaCommandType::EXIT;
  }
  std::stringstream ss;
  ss << "Unrecognized command: '" << command << "'.";
  throw meta_command_parse_error(ss.str(), command);
}

