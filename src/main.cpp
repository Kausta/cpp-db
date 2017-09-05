// main.cpp
// Created by Caner Korkmaz on 5/9/2017.
// Copyright 2017 Caner Korkmaz
//

#include <string>
#include <iostream>
#include "MetaCommand.h"
#include "Statement.h"

using namespace cpp_db;

void print_prompt(){
  std::cout << "db > ";
}

std::string read_input(){
  auto line = std::string{};
  if(!std::getline(std::cin, line)){
    throw std::runtime_error("Error reading input.");
  }
  return line;
}

int main(int /*argc*/, char* /*argv*/[]){
  try{
    while(true) {
      print_prompt();
      auto input = read_input();

      try {
        // If the command is a meta command
        if (input[0]=='.') {
          auto const command_type = parse_meta_command(input);
          switch (command_type) {
            case MetaCommandType::EXIT:return EXIT_SUCCESS;
          }
        }

        auto statement = parse_statement(input);
        statement->execute();
        std::cout << "Executed.\n";
      } catch (parse_error &err) {
        std::cerr << err.what() << '\n';
      }
    }
  } catch (std::exception& err){
    std::cerr << "Error: " << err.what() << '\n';
    return EXIT_FAILURE;
  }
}