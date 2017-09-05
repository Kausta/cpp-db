// InsertStatement.h
// Created by Caner Korkmaz on 5/9/2017.
// Copyright 2017 Caner Korkmaz
//

#ifndef CPP_DB_INSERTSTATEMENT_H
#define CPP_DB_INSERTSTATEMENT_H

#include "StatementBase.h"

namespace cpp_db{

class InsertStatement : public Statement{
 public:
  explicit InsertStatement(const std::string &command)
      : Statement(command)
  {}

  void execute() override;

};

}

#endif //CPP_DB_INSERTSTATEMENT_H
