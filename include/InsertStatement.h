// InsertStatement.h
// Created by Caner Korkmaz on 5/9/2017.
// Copyright 2017 Caner Korkmaz
//

#ifndef CPP_DB_INSERTSTATEMENT_H
#define CPP_DB_INSERTSTATEMENT_H

#include "StatementBase.h"
#include "Table.h"

namespace cpp_db {

/**
 * Insert command statement, currently supports only a specific row
 */
class InsertStatement : public Statement {
 public:
  explicit InsertStatement(std::string command)
      : Statement(std::move(command)), row_(parse_row()) {}

  void execute(Table& table) override;

  const Row &row() const { return row_; }
 private:
  Row parse_row();

  Row row_;
};

}

#endif //CPP_DB_INSERTSTATEMENT_H
