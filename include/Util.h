// Util.h
// Created by Caner Korkmaz on 5/9/2017.
// Copyright 2017 Caner Korkmaz
//

#ifndef CPP_DB_UTIL_H
#define CPP_DB_UTIL_H

#include <string>

namespace util{
  bool starts_with(const std::string& text, const std::string& search){
    if(text.length() < search.length())
      return false;
    return text.compare(0, search.length(), search) == 0;
  }
}

#endif //CPP_DB_UTIL_H
