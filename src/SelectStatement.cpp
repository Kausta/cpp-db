// SelectStatement.cpp
// Created by Caner Korkmaz on 5/9/2017.
// Copyright 2017 Caner Korkmaz
//

#include "SelectStatement.h"

void cpp_db::SelectStatement::execute() {
  for (size_t i = 0; i < table_.size(); i++) {
    std::cout << table_[i] << '\n';
  }
}
