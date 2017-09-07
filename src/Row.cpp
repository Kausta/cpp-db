// Row.cpp
// Created by Caner Korkmaz on 5/9/2017.
// Copyright 2017 Caner Korkmaz
//

#include "Row.h"

#include <algorithm>
#include "Error.h"

using namespace cpp_db;

std::ostream &::cpp_db::operator<<(std::ostream &os, const Row &row) {
  return os << "Row{" << row.id << ", " << row.username.data() << ", " << row.email.data() << "}";
}
std::istream &::cpp_db::operator>>(std::istream &is, Row &row) {
  std::string id, username, email;
  if (!(is >> id >> username >> email)) {
    throw parse_error("Cannot parse row!");
  }
  if (id[0]=='-') {
    throw parse_error("ID cannot be negative", id);
  }
  try {
    if (sizeof(size_t)==sizeof(uint32_t)) {
      row.id = std::stoul(id);
    } else {
      row.id = std::stoull(id);
    }
  } catch (std::logic_error &err) {
    throw parse_error("ID too large!", id);
  }
  if (username.length() > Row::USERNAME_SIZE) {
    throw parse_error("Username too long", username);
  }
  std::copy(username.begin(), username.end(), row.username.begin());
  if (email.length() > Row::EMAIL_SIZE) {
    throw parse_error("Email too long", email);
  }
  std::copy(email.begin(), email.end(), row.email.begin());
  return is;
}
