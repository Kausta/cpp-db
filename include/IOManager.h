// IOManager.h
// Created by Caner Korkmaz on 8/9/2017.
// Copyright 2017 Caner Korkmaz
//

#ifndef CPP_DB_IOMANAGER_H
#define CPP_DB_IOMANAGER_H

#include <iostream>
#include <functional>

namespace cpp_db{
class IOManager{
 public:
  static IOManager& instance(){
    static IOManager manager;
    return manager;
  }

  void print_prompt(){
    out() << "db > ";
  }

  std::string read_line(){
    std::string line;
    // Discard whitespace and read the rest of the line
    if (!std::getline(in() >> std::ws, line)) {
      throw std::runtime_error("Error reading input.");
    }
    return line;
  }

  std::ostream& out(){
    return output_stream_.get();
  }
  const std::ostream& out() const{
    return output_stream_.get();
  }
  void set_output(std::ostream& os){
    output_stream_ = os;
  }

  std::istream& in(){
    return input_stream_.get();
  }
  const std::istream& in() const{
    return input_stream_.get();
  }
  void set_input(std::istream& is){
    input_stream_ = is;
  }
 private:
  IOManager()
      : output_stream_(std::cout)
      , input_stream_(std::cin)
  {}

  std::reference_wrapper<std::ostream> output_stream_;
  std::reference_wrapper<std::istream> input_stream_;
};
}

#endif //CPP_DB_IOMANAGER_H
