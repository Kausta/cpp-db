// InsertStatement.h
// Created by Caner Korkmaz on 5/9/2017.
// Copyright 2017 Caner Korkmaz
//

#ifndef CPP_DB_INSERTSTATEMENT_H
#define CPP_DB_INSERTSTATEMENT_H

#include "StatementBase.h"
#include "Table.h"

namespace cpp_db{

class InsertStatement : public Statement{
 public:
  explicit InsertStatement(Table& table, std::string command)
      : Statement(table, std::move(command))
      , row_(parse_row())
  {}

  void execute() override;

  const Row& row() const { return row_; }
 private:
  Row parse_row();

  Row row_;
};

}

#endif //CPP_DB_INSERTSTATEMENT_H
