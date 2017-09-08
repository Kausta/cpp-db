// SelectStatement.cpp
// Created by Caner Korkmaz on 5/9/2017.
// Copyright 2017 Caner Korkmaz
//

#include "SelectStatement.h"
#include "IOManager.h"

void cpp_db::SelectStatement::execute(Table& table) {
  IOManager& io_manager = IOManager::instance();
  for (size_t i = 0; i < table.size(); i++) {
     io_manager.out() << table[i] << '\n';
  }
}
