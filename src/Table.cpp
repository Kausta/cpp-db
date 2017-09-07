// Table.cpp
// Created by Caner Korkmaz on 5/9/2017.
// Copyright 2017 Caner Korkmaz
//

#include "Table.h"

#include <cstring>

using namespace cpp_db;

buffer_ptr cpp_db::allocate_buffer(size_t bytes) {
  return std::make_unique<uint8_t[]>(bytes);
}

void Table::push_row(const Row &row) {
  memcpy(row_slot(num_rows), &row, sizeof(Row));
  num_rows++;
}

Row &Table::operator[](size_t row_num) {
  return *reinterpret_cast<Row *>(row_slot(row_num));
}
const Row &Table::operator[](size_t row_num) const {
  return *reinterpret_cast<const Row *>(row_slot(row_num));
}

void *cpp_db::Table::row_slot(size_t row_num) {
  auto page_num = row_num/ROWS_PER_PAGE;
  if (page_num >= pages.size()) {
    pages.resize(page_num + 1);
  }
  auto &page = pages[page_num];
  if (!page) {
    page = allocate_buffer(PAGE_SIZE);
  }
  auto row_offset = row_num%ROWS_PER_PAGE;
  auto byte_offset = row_offset*sizeof(Row);
  return page.get() + byte_offset;
}

const void *Table::row_slot(size_t row_num) const {
  auto page_num = row_num/ROWS_PER_PAGE;
  if (page_num > pages.size()) {
    throw std::out_of_range("Trying to accessing non-existent row page!");
  }
  auto &page = pages[page_num];
  if (!page) {
    throw std::logic_error("Accessing non initialized row page in const!");
  }
  auto row_offset = row_num%ROWS_PER_PAGE;
  auto byte_offset = row_offset*sizeof(Row);
  return page.get() + byte_offset;;
}


