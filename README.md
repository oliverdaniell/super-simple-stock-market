# Assumptions
- In absence of any precision requirements, double precision arithmetic is used throughout. In practice a big decimal library such as [boost multiprecision library](http://www.boost.org/doc/libs/1_64_0/libs/multiprecision/doc/html/boost_multiprecision/tut/floats/cpp_dec_float.html) may be appropriate.
- Architectural design is beyond the scope of this exercise.

# Error handling
- Pre and post conditions are enforced using assertions, input is assumed to have been validated