// Statement.h
// Created by Caner Korkmaz on 5/9/2017.
// Copyright 2017 Caner Korkmaz
//

#ifndef CPP_DB_STATEMENT_H
#define CPP_DB_STATEMENT_H

#include <string>
#include <iostream>
#include <memory>

#include "StatementBase.h"
#include "InsertStatement.h"
#include "SelectStatement.h"
#include "Table.h"

namespace cpp_db{

std::unique_ptr<Statement> parse_statement(Table& table, std::string command);

}

#endif //CPP_DB_STATEMENT_H
