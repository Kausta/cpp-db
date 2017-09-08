// main.cpp
// Created by Caner Korkmaz on 5/9/2017.
// Copyright 2017 Caner Korkmaz
//

#include <string>
#include <iostream>
#include "IOManager.h"
#include "MetaCommand.h"
#include "Statement.h"

using namespace cpp_db;

int main(int /*argc*/, char * /*argv*/[]) {
  try {
    // Initiate the default database table
    Table table;
    IOManager& io_manager = IOManager::instance();
    while (true) {
      io_manager.print_prompt();
      auto input = io_manager.read_line();

      try {
        // If the command is a meta command
        if (is_meta_command(input)) {
          auto const command_type = parse_meta_command(input);
          switch (command_type) {
            case MetaCommandType::EXIT:return EXIT_SUCCESS;
          }
          continue;
        }

        // Parse and execute the command
        auto statement = parse_statement(input);
        statement->execute(table);
        io_manager.out() << "Executed.\n";
      } catch (error_base &err) {
        std::cerr << "Error: " << err.what() << '\n';
      }
    }
  } catch (std::runtime_error &err) {
    std::cerr << "Runtime Error: " << err.what() << '\n';
  } catch (std::logic_error &err) {
    std::cerr << "Logic Error: " << err.what() << '\n';
  }
  return EXIT_FAILURE;
}