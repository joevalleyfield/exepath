project(exepath)

cmake_minimum_required(VERSION 3.3)

add_library(exepath SHARED
  exepath.h exepath.cpp)

set_target_properties(exepath
  PROPERTIES COMPILE_DEFINITIONS "BUILDING_EXEPATH"
)

enable_testing()

add_executable(test_exepath
  catch.hpp 
  test_exepath.cpp)

add_definitions(
  "-DLIBRARY_FILEPATH=\"$<TARGET_FILE:exepath>\""
  "-DTEST_FILEPATH=\"$<TARGET_FILE:test_exepath>\""
)

set_source_files_properties(test_exepath.cpp
  PROPERTIES
  COMPILE_DEFINITIONS "CATCH_CONFIG_MAIN"
)

target_link_libraries(test_exepath
  exepath )

add_test(exepath test_exepath)
