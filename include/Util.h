// Util.h
// Created by Caner Korkmaz on 5/9/2017.
// Copyright 2017 Caner Korkmaz
//

#ifndef CPP_DB_UTIL_H
#define CPP_DB_UTIL_H

#include <string>

namespace util {
/**
* Helper for checking whether the given text starts with the search text
*/
bool starts_with(const std::string &text, const std::string &search);
}

#endif //CPP_DB_UTIL_H
