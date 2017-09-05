// Table.cpp
// Created by Caner Korkmaz on 5/9/2017.
// Copyright 2017 Caner Korkmaz
//

#include "Table.h"
#include "Error.h"

using namespace cpp_db;

buffer_ptr cpp_db::allocate_buffer(size_t bytes){
 return std::make_unique<uint8_t[]>(bytes);
}

void Table::push_row(const Row &row) {
  if (num_rows >= TABLE_MAX_ROWS) {
    throw error_base("Table full, cannot insert more!");
  }
  Row::serialize(row, row_slot(num_rows));
  num_rows++;
}

void *cpp_db::Table::row_slot(size_t row_num) {
  auto page_num = row_num/ROWS_PER_PAGE;
  auto &page = pages[page_num];
  if (!page) {
    page = allocate_buffer(PAGE_SIZE);
  }
  auto row_offset = row_num % ROWS_PER_PAGE;
  auto byte_offset = row_offset * sizeof(Row);
  return page.get() + byte_offset;
}

Row Table::operator[](size_t row_num) {
  return Row::deserialize(row_slot(row_num));
}


