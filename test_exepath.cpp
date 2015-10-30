#include "catch.hpp"

#include "exepath.h"

int f() {
  return 0;
}

TEST_CASE( "Find the object file exepath() is in" ) {
//  REQUIRE(exepath() == "... /libexepath.dylib");
  REQUIRE(exepath() == LIBRARY_FILEPATH);
}

TEST_CASE( "Find the object file f() is in" ) {
//  REQUIRE(exepath((void*)f) == "... /./test_exepath");
  REQUIRE(exepath((void*)f) == TEST_FILEPATH);
}
