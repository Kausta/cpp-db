// meta_command.cpp
// Created by Caner Korkmaz on 8/9/2017.
// Copyright 2017 Caner Korkmaz
//

#include <catch.hpp>

#include <string>
#include <MetaCommand.h>

using namespace std::string_literals;

// Remainder: don't use comma in test name for now (https://github.com/philsquared/Catch/issues/932)
// (detected, parsed)*
SCENARIO("Meta commands can be detected parsed and executed", "[meta-command]"){
  GIVEN("A non meta command"){
    auto const& command = "insert 1 FooBar info@foobar.org"s;
    WHEN("It is checked for meta commands"){
      auto is_meta = cpp_db::is_meta_command(command);
      THEN("It is identified as non-meta"){
        REQUIRE(!is_meta);
      }
    }
    WHEN("It is not checked and given to parse"){
      THEN("It throws not meta command exception"){
        REQUIRE_THROWS_AS(cpp_db::parse_meta_command(command), cpp_db::not_meta_command_error);
      }
    }
  }
  GIVEN("An unknown meta command"){
    auto const& command = ".meta"s;
    WHEN("It is checked for meta commands"){
      auto is_meta = cpp_db::is_meta_command(command);
      THEN("It is identified as meta"){
        REQUIRE(is_meta);
      }
    }
    WHEN("It is parsed"){
      THEN("It throws meta command parse error"){
        REQUIRE_THROWS_AS(cpp_db::parse_meta_command(command), cpp_db::meta_command_parse_error);
      }
    }
  }
  GIVEN("Exit meta command"){
    auto const& command = ".exit"s;
    WHEN("It is parsed"){
      auto command_type = cpp_db::parse_meta_command(command);
      THEN("It is identified as exit command"){
        REQUIRE(command_type == cpp_db::MetaCommandType::EXIT);
      }
    }
  }
}