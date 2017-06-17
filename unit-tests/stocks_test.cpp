#include "catch.hpp"
#include <cmath>
#include <limits>
#include <stocks.h>

TEST_CASE("Given any price as input, calculate the dividend yield", "[1.a.i]")
{
    SECTION("TEA")
    {
        REQUIRE(stocks::dividend_yield_common(100.0, 0.0) ==
                Approx(0.0).margin(std::nextafter(0.0, 1.0)));
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
        REQUIRE(stocks::dividend_yield_preferred(100.0, 0.02, 100.0) == Approx(0.02));
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
        REQUIRE(std::isinf(stocks::price_earnings_ratio(100.0, 0.0)));
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

TEST_CASE(
    "Record a trade, with timestamp, quantity of shares, buy or sell indicator and traded price",
    "[1.a.iii]")
{
	SECTION("stocks::trade constructor 1")
	{
		auto const timestamp = std::chrono::system_clock::now();
		auto trade = stocks::trade{ timestamp, 100, stocks::buy_sell_indicator::buy, 50.0 };

		REQUIRE(trade.buy_sell() == stocks::buy_sell_indicator::buy);
		REQUIRE(trade.quantity_of_shares() == 100);
		REQUIRE(trade.timestamp() == timestamp);
		REQUIRE(trade.traded_price() == Approx(50.0));
	}

	SECTION("stocks::trade constructor 2")
	{
		auto const timestamp = std::chrono::system_clock::now();
		auto trade = stocks::trade{ timestamp, 10, stocks::buy_sell_indicator::sell, 5.0 };

		REQUIRE(trade.buy_sell() == stocks::buy_sell_indicator::sell);
		REQUIRE(trade.quantity_of_shares() == 10);
		REQUIRE(trade.timestamp() == timestamp);
		REQUIRE(trade.traded_price() == Approx(5.0));
	}
}