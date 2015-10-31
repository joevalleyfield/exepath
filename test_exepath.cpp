#include "catch.hpp"

#include "exepath.h"

int f() {
  return 0;
}

const std::string normalize_path(const std::string path) {
#if _WIN32
  char buf[1024];
  GetFullPathName(path.c_str(), 1024, buf, 0);
  return buf;
#else
  return path;
#endif
}

TEST_CASE( "Find the object file exepath() is in" ) {
//  REQUIRE(exepath() == "... /libexepath.dylib");
  REQUIRE(exepath() == normalize_path(LIBRARY_FILEPATH));
}

TEST_CASE( "Find the object file f() is in" ) {
//  REQUIRE(exepath((void*)f) == "... /./test_exepath");
  REQUIRE(exepath((void*)f) == normalize_path(TEST_FILEPATH));
}
