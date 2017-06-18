#pragma once

#include <algorithm>
#include <assert.h>
#include <chrono>
#include <cmath>
#include <numeric>
#include <set>

/** @brief Namespace for simple stocks homework, unless otherwise stated all values are in pennies
 */
namespace stocks
{
/** @brief Calculate the dividend yield for common stock
 * @param[in] price The traded price of a share
 * @param[in] last_dividend The value of the last dividend
 */
double dividend_yield_common(double price, double last_dividend);

/** @brief Calculate the dividend yield for preferred stock
 * @param[in] price The traded price of a share
 * @param[in] fixed_dividend_fraction Almost all preferred shares have a negotiated, fixed-dividend
 * amount. The dividend is specified as a fraction of the par value
 * @param[in] par_value The stated or face value
 */
double dividend_yield_preferred(double price, double fixed_dividend_fraction, double par_value);

/** @brief Calculate the ratio of the price to the dividend
 * @param[in] price The traded price of a share
 * @param[in] dividend The dividend paid
 */
double price_earnings_ratio(double price, double dividend);

/** @brief Emum to track if a trade was a buy or a sell */
enum class buy_sell_indicator
{
    buy,
    sell
};

/** @brief The trade class stores the details of a trade */
class trade
{
  public:
    using timestamp_type = std::chrono::time_point<std::chrono::system_clock>;

    /** @brief Constructor for trade class
     * @param[in] timestamp The time at which the trade occurred
     * @param[in] quantity_of_shares Number of shares traded (quantity_of_shares > 0)
     * @param[in] buy_sell_indicator Were shares bought or sold
     * @param[in] traded_price The total price of the trade (traded_price >= 0.0)
     */
    trade(timestamp_type const &timestamp, int quantity_of_shares, buy_sell_indicator buy_sell,
          double traded_price);

    /** @brief The time at which the trade occurred */
    timestamp_type timestamp() const;

    /** @brief Number of shares traded */
    int quantity_of_shares() const;

    /** @brief Were shares bought or sold */
    buy_sell_indicator buy_sell() const;

    /** @brief The total price of the trade */
    double traded_price() const;

  private:
    timestamp_type m_timestamp;
    int m_quantity_of_shares;
    buy_sell_indicator m_buy_sell;
    double m_traded_price;
};

/** @brief Calculate the volume weighted stock price, assume this includes all shares traded (buy or
 * sell)
 * @param[in] begin Iterator to container of trades
 * @param[in] end Iterator to container of trades
 */
template <typename Iterator> double volume_weighted_stock_price(Iterator begin, Iterator end)
{
    auto weighted_traded_price =
        std::decay_t<decltype(begin->traded_price() * begin->quantity_of_shares())>{};
    auto total_shares_bought = std::decay_t<decltype(begin->quantity_of_shares())>{};

    for (; begin != end; ++begin)
    {
        weighted_traded_price += begin->traded_price() * begin->quantity_of_shares();
        total_shares_bought += begin->quantity_of_shares();
    }

    return weighted_traded_price / total_shares_bought;
}

/** @brief Calculate the GBCE all share index, this is the geometric mean of prices for all stocks
 * @param[in] begin Iterator to prices
 * @param[in] end Iterator to prices
 */
template <typename Iterator> double gbce_all_share_index(Iterator begin, Iterator end)
{
#ifndef NDEBUG
    for (auto it = begin; it != end; ++it)
    {
        assert(*it > 0.0);
    }
#endif

    auto product = std::accumulate(begin, end, 1.0, [](auto a, auto b) { return a * b; });
    return std::pow(product, 1.0 / std::distance(begin, end));
}

/** @brief Calculate the GBCE all share index, this is the geometric mean of prices for all stocks
* @param[in] begin Iterator to prices
* @param[in] end Iterator to prices
*/
template <typename Iterator> double gbce_all_share_index_stable(Iterator begin, Iterator end)
{
#ifndef NDEBUG
	for (auto it = begin; it != end; ++it)
	{
		assert(*it > 0.0);
	}
#endif

	auto product = std::accumulate(begin, end, 0.0, [](auto a, auto b) { return a + std::log(b); });
	return std::exp(product / std::distance(begin,end));
}
}