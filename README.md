# Introduction
- The example requires CMake v3.2 or greater and a c++14 compatible compiler.
- Build instructions
```
mkdir build
cd build
cmake ..
cmake --build .
```
- Example usage can be found in unit-tests/stocks_test.cpp
- Source code can be found in src/
- Documentation (Doxygen) can be found inline in the header files

# Assumptions
- In the absence of any precision requirements, double precision arithmetic is used throughout. In practice a big decimal library such as [boost multiprecision library](http://www.boost.org/doc/libs/1_64_0/libs/multiprecision/doc/html/boost_multiprecision/tut/floats/cpp_dec_float.html) may be appropriate.

# Error handling
- Pre and post conditions are enforced using assertions, input is assumed to have been validated
