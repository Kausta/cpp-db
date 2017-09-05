// StatementBase.h
// Created by Caner Korkmaz on 5/9/2017.
// Copyright 2017 Caner Korkmaz
//

#ifndef CPP_DB_STATEMENTBASE_H
#define CPP_DB_STATEMENTBASE_H

#include <string>
#include "Error.h"
#include "Table.h"

namespace cpp_db {
class statement_parse_error : public parse_error {
 public:
  statement_parse_error(const std::string &description, std::string command)
      : parse_error(description, std::move(command)) {}
};

class Statement {
 public:
  explicit Statement(Table& table, std::string command)
      : table_(table)
      , command_(std::move(command)) {}
  virtual ~Statement() = default;

  virtual void execute() = 0;

  Table& table() { return table_; }
  const Table& table() const { return table_; }
  const std::string &command() const { return command_; }
 protected:
  Table& table_;
  std::string command_;
};
}

#endif //CPP_DB_STATEMENTBASE_H
