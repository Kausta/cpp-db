// ParseError.h
// Created by Caner Korkmaz on 5/9/2017.
// Copyright 2017 Caner Korkmaz
//

#ifndef CPP_DB_PARSEERROR_H
#define CPP_DB_PARSEERROR_H

#include <stdexcept>
#include <utility>

namespace cpp_db {
/**
 * Base class for errors that doesn't require the app to terminate
 */
class error_base : public std::runtime_error {
 public:
  explicit error_base(const std::string &description) : runtime_error(description) {}
};

/**
 * Error class for parsing errors in commands
 */
class parse_error : public error_base {
 public:
  explicit parse_error(const std::string &description)
      : error_base(form_error_message(description)), command_() {}
  parse_error(const std::string &description, std::string command)
      : error_base(form_error_message(description, command)), command_(std::move(command)) {}

  bool has_command() const { return !command_.empty(); }
  const std::string &command() const { return command_; };
 private:
  static std::string form_error_message(const std::string &description);
  static std::string form_error_message(const std::string &description, const std::string &command);

  std::string command_;
};

}

#endif //CPP_DB_PARSEERROR_H
