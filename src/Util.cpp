// Util.cpp
// Created by Caner Korkmaz on 5/9/2017.
// Copyright 2017 Caner Korkmaz
//

#include "Util.h"

using namespace util;

bool util::starts_with(const std::string &text, const std::string &search) {
  if(text.length() < search.length())
    return false;
  return text.compare(0, search.length(), search) == 0;
}
