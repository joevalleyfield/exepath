## exepath

This bit of code finds an object file (exe or dll) on Windows/Mac/Linux.

It is packaged here with a CMake build and a couple of unit tests, but is 
really meant to be extracted and used however you see fit.

## Code Example

``` c++

#include "exepath.h"
#include <iostream>

int main(int argc, const char *argv[] ) {
  assert(exepath() == LIBRARY_FILEPATH);

  std::cerr << "Path to executable/library with exepath: "
    << exepath() << "\n";
  std::cerr << "Path to this executable: "
    << exepath((void *)main) << "\n";
  return 0;
}

```

## License

Public Domain

The author or authors of this project dedicate any and all copyright interest
in the contained code to the public domain. We make this dedication for the
benefit of the public at large and to the detriment of our heirs and
successors. We intend this dedication to be an overt act of relinquishment
in perpetuity of all present and future rights to this code under copyright
law. 

This project includes catch-based tests and a snapshot of catch.hpp.

Catch has the following license:

> Copyright (c) 2012 Two Blue Cubes Ltd. All rights reserved.
>
> Distributed under the Boost Software License, Version 1.0. (See accompanying
> file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

