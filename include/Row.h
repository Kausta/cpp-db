// Row.h
// Created by Caner Korkmaz on 5/9/2017.
// Copyright 2017 Caner Korkmaz
//

#ifndef CPP_DB_ROW_H
#define CPP_DB_ROW_H

#include <array>
#include <iostream>

namespace cpp_db {

/**
 * Current default row for the db, will change in the future for a complete system
 */
struct Row {
  static constexpr size_t USERNAME_SIZE = 32 + 1;
  static constexpr size_t EMAIL_SIZE = 255 + 1;

  size_t id;
  std::array<char, USERNAME_SIZE> username;
  std::array<char, EMAIL_SIZE> email;

  Row() = default;
};

std::ostream &operator<<(std::ostream &os, const Row &row);
std::istream &operator>>(std::istream &is, Row &row);

}

#endif //CPP_DB_ROW_H
