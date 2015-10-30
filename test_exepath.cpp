#include "catch.hpp"

#include "exepath.h"

int f() {
  return 0;
}

std::string library_filepath() {
#if _WIN32
  char buf[1024];
  GetFullPathName(LIBRARY_FILEPATH, 1024, buf, 0);
  return buf;
#else
  return LIBRARY_FILEPATH;
#endif
}

std::string thisexe_filepath() {
#if _WIN32
  char buf[1024];
  GetFullPathName(TEST_FILEPATH, 1024, buf, 0);
  return buf;
#else
  return TEST_FILEPATH;
#endif
}

TEST_CASE( "Find the object file exepath() is in" ) {
//  REQUIRE(exepath() == "... /libexepath.dylib");
  REQUIRE(exepath() == library_filepath());
}

TEST_CASE( "Find the object file f() is in" ) {
//  REQUIRE(exepath((void*)f) == "... /./test_exepath");
  REQUIRE(exepath((void*)f) == thisexe_filepath());
}
