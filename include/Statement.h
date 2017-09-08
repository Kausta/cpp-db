// Statement.h
// Created by Caner Korkmaz on 5/9/2017.
// Copyright 2017 Caner Korkmaz
//

#ifndef CPP_DB_STATEMENT_H
#define CPP_DB_STATEMENT_H

#include <string>
#include <memory>

#include "StatementBase.h"
#include "InsertStatement.h"
#include "SelectStatement.h"
#include "Table.h"

namespace cpp_db {
/**
 * Parses the given statement and returns a unique ptr to appropriate statement type
 * @param command Command to parse ( and to execute on the table)
 * @return Appropriate statement class
 * @throws statement_parse_error if the statement is not known
 */
std::unique_ptr<Statement> parse_statement(std::string command);

}

#endif //CPP_DB_STATEMENT_H
