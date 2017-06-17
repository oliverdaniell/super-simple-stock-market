#include "include\stocks.h"

namespace stocks
{
double dividend_yield_common(double price, double last_dividend)
{
    return 0.0;
}
double dividend_yield_preferred(double price, double fixed_dividend, double par_value)
{
    return 0.0;
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