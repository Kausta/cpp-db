// MetaCommand.h
// Created by Caner Korkmaz on 5/9/2017.
// Copyright 2017 Caner Korkmaz
//

#ifndef CPP_DB_METACOMMAND_H
#define CPP_DB_METACOMMAND_H

#include <string>
#include "Error.h"

namespace cpp_db {

/**
 * Possible meta command types
 */
enum class MetaCommandType {
  EXIT
};

bool is_meta_command(const std::string &command);
/**
 * Parses meta commands
 * @param command Command to parse
 * @return Parsed command
 * @throws meta_command_parse_error if the command is not a known meta command
 */
MetaCommandType parse_meta_command(const std::string &command);

/**
 * Meta command specific parsing errors
 */
class meta_command_parse_error : public parse_error {
 public:
  meta_command_parse_error(const std::string &description, std::string command)
      : parse_error(description, std::move(command)) {}
};

/**
 * Non meta command is given to parse meta command
 */
class not_meta_command_error : public std::logic_error {
 public:
  explicit not_meta_command_error(const std::string &description)
      : logic_error(description) {}
};

}

#endif //CPP_DB_METACOMMAND_H
