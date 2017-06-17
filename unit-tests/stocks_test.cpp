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

TEST_CASE("Given any price as input, calculate the P/E Ratio", "[1.a.ii]")
{
	SECTION("TEA")
	{
		REQUIRE(std::isinf( stocks::price_earnings_ratio(100.0, 0.0)));
	}
	SECTION("POP")
	{
		REQUIRE(stocks::price_earnings_ratio(100.0, 8.0) == Approx(12.5));
	}
	SECTION("ALE")
	{
		REQUIRE(stocks::price_earnings_ratio(60.0, 23.0) == Approx(2.61).epsilon(0.01));
	}
	SECTION("GIN")
	{
		REQUIRE(stocks::price_earnings_ratio(100.0, 2.0) == Approx(50.0));
	}
	SECTION("JOE")
	{
		REQUIRE(stocks::price_earnings_ratio(250.0, 13.0) == Approx(19.2).epsilon(0.01));
	}
}