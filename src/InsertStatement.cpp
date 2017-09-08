// InsertStatement.cpp
// Created by Caner Korkmaz on 5/9/2017.
// Copyright 2017 Caner Korkmaz
//

#include "InsertStatement.h"

#include <sstream>

using namespace cpp_db;

void cpp_db::InsertStatement::execute(Table& table) {
  table.push_row(row_);
}
Row cpp_db::InsertStatement::parse_row() {
  std::stringstream ss(command_);

  std::string tmp_for_insert;
  Row row{};

  ss >> tmp_for_insert >> row;

  return row;
}
