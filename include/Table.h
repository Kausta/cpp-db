// Table.h
// Created by Caner Korkmaz on 5/9/2017.
// Copyright 2017 Caner Korkmaz
//

#ifndef CPP_DB_TABLE_H
#define CPP_DB_TABLE_H

#include <array>
#include <memory>
#include "Row.h"

namespace cpp_db{

static_assert(sizeof(uint8_t) == 1);
using buffer_ptr = std::unique_ptr<uint8_t[]>;
buffer_ptr allocate_buffer(size_t bytes);

class Table{
 public:
  static constexpr size_t PAGE_SIZE = 4096;
  static constexpr size_t TABLE_MAX_PAGES = 100;
  static constexpr size_t ROWS_PER_PAGE = PAGE_SIZE / sizeof(Row);
  static constexpr size_t TABLE_MAX_ROWS = ROWS_PER_PAGE * TABLE_MAX_PAGES;

 public:
  Table() = default;

  void push_row(const Row& row);
  Row operator[](size_t row_num);

  size_t size() const { return num_rows; }
 private:
  std::array<buffer_ptr, TABLE_MAX_PAGES> pages;
  size_t num_rows = 0;

  void* row_slot(size_t row_num);
};

}

#endif //CPP_DB_TABLE_H
