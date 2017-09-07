// SelectStatement.h
// Created by Caner Korkmaz on 5/9/2017.
// Copyright 2017 Caner Korkmaz
//

#ifndef CPP_DB_SELECTSTATEMENT_H
#define CPP_DB_SELECTSTATEMENT_H

#include "StatementBase.h"

namespace cpp_db {

/**
 * Select command statement, currently supports only printing all rows
 */
class SelectStatement : public Statement {
 public:
  explicit SelectStatement(Table &table, std::string command)
      : Statement(table, std::move(command)) {}

  void execute() override;

};

}

#endif //CPP_DB_SELECTSTATEMENT_H
