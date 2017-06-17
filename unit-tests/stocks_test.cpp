#include "catch.hpp"
#include <limits>
#include <cmath>
#include <stocks.h>


TEST_CASE("Given any price as input, calculate the dividend yield","[1.a.i]")
{
	SECTION("TEA")
	{
		REQUIRE(stocks::dividend_yield_common(100.0, 0.0) == Approx(0.0).margin(std::nextafter(0.0,1.0)));
	}
	SECTION("POP")
	{
		REQUIRE(stocks::dividend_yield_common(100.0, 8.0) == Approx(0.08));
	}
	SECTION("ALE")
	{
		REQUIRE(stocks::dividend_yield_common(60.0, 23.0) == Approx(0.383).epsilon(0.001));
	}
	SECTION("GIN")
	{
		REQUIRE(stocks::dividend_yield_preferred(100.0,0.02,100.0) == Approx(0.02));
	}
	SECTION("JOE")
	{
		REQUIRE(stocks::dividend_yield_common(250.0, 13.0) == Approx(0.052));
	}
}