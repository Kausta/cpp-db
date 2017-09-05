// Row.cpp
// Created by Caner Korkmaz on 5/9/2017.
// Copyright 2017 Caner Korkmaz
//

#include "Row.h"

#include <cstring>
#include <algorithm>
#include <limits>
#include "Error.h"

using namespace cpp_db;

std::ostream &::cpp_db::operator<<(std::ostream &os, const Row &row) {
  return os << "Row{" << row.id << ", " << row.username.data() << ", " << row.email.data() << "}";
}
std::istream &::cpp_db::operator>>(std::istream &is, Row &row) {
  std::string id, username, email;
  if (!(is >> id >> username >> email)) {
    throw error_base("Cannot parse row!");
  }
  if(id[0] == '-'){
    throw error_base("ID cannot be negative");
  }
  try {
    if(sizeof(size_t) == sizeof(uint32_t)){
      row.id = std::stoul(id);
    } else {
      row.id = std::stoull(id);
    }
  } catch (std::logic_error& err){
    throw error_base("ID too large!");
  }
  std::copy(username.begin(), username.end(), row.username.begin());
  if (email.length() > Row::EMAIL_SIZE) {
    throw error_base("Email too long");
  }
  std::copy(email.begin(), email.end(), row.email.begin());
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
