#include "include\stocks.h"
#include <assert.h>

namespace stocks
{
double dividend_yield_common(double price, double last_dividend)
{
	assert(price > 0.0);
	assert(last_dividend >= 0.0);
	return last_dividend / price;
}
double dividend_yield_preferred(double price, double fixed_dividend_fraction, double par_value)
{
	assert(price > 0.0);
	assert(fixed_dividend_fraction >= 0.0);
	assert(par_value >= 0.0);
	return fixed_dividend_fraction*par_value / price;
}
double price_earnings_ratio(double price, double dividend)
{
    return 0.0;
}
trade::trade(timestamp_type const &timestamp, int quantity_of_shares, buy_sell_indicator buy_sell,
             double traded_price)
{
}
trade::timestamp_type trade::timestamp() const
{
    return timestamp_type();
}
int trade::quantity_of_shares() const
{
    return 0;
}
buy_sell_indicator trade::buy_sell() const
{
    return buy_sell_indicator();
}
double trade::traded_price() const
{
    return 0.0;
}
} // namespace stocks