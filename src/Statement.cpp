// Statement.cpp
// Created by Caner Korkmaz on 5/9/2017.
// Copyright 2017 Caner Korkmaz
//

#include "Statement.h"

#include <sstream>
#include "Util.h"

using namespace cpp_db;

std::unique_ptr<Statement> cpp_db::parse_statement(std::string command) {
  if (util::starts_with(command, "insert")) {
    return std::make_unique<InsertStatement>(std::move(command));
  }
  if (util::starts_with(command, "select")) {
    return std::make_unique<SelectStatement>(std::move(command));
  }

  std::stringstream ss;
  ss << "Unrecognized keyword at start of '" << command << "'.";
  throw statement_parse_error(ss.str(), std::move(command));
}
