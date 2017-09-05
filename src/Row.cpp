// Row.cpp
// Created by Caner Korkmaz on 5/9/2017.
// Copyright 2017 Caner Korkmaz
//

#include "Row.h"

#include "Error.h"

using namespace cpp_db;

std::ostream &::cpp_db::operator<<(std::ostream &os, const Row &row) {
  return os << "Row{" << row.id << ", " << row.username.data() << ", " << row.email.data() << "}";
}
std::istream &::cpp_db::operator>>(std::istream &is, Row &row) {
  if(!(is >> row.id >> row.username.data() >> row.email.data())){
    throw error_base("Cannot parse row!");
  }
  return is;
}

void Row::serialize(const Row &row, void *destination) {
  memcpy(destination, &row, sizeof(Row));
}
Row Row::deserialize(void *source) {
  Row row{};
  memcpy(&row, source, sizeof(Row));
  return row;
}
