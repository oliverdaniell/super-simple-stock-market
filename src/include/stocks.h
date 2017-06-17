#include <chrono>

/** @brief Namespace for simple stocks homework, unless otherwise stated all values are in dollars
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
 * @param[in] fixed_dividend Almost all preferred shares have a negotiated, fixed-dividend amount.
 * The dividend is specified as a fixed amount
 * @param[in] par_value The stated or face value
 */
double dividend_yield_preferred(double price, double fixed_dividend, double par_value);

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
     * @param[in] traded_price The price per share traded (traded_price >= 0.0)
     */
    trade(timestamp_type const &timestamp, int quantity_of_shares, buy_sell_indicator buy_sell,
          double traded_price);

    /** @brief The time at which the trade occurred */
    timestamp_type timestamp() const;

    /** @brief Number of shares traded */
    int quantity_of_shares() const;

    /** @brief Were shares bought or sold */
    buy_sell_indicator buy_sell() const;

    /** @brief The price per share traded */
    double traded_price() const;

  private:
    timestamp_type m_timestamp;
    int m_quantity_of_shares;
    buy_sell_indicator m_buy_sell;
    double m_traded_price;
};

/** @brief Calculate the volume weighted stock price, this is the mean prices per share
 * @param[in] begin Iterator to container of trades
 * @param[in] end Iterator to container of trades
 */
template <typename Iterator> double volume_weighted_stock_price(Iterator begin, Iterator end)
{
    return 0.0;
}

/** @brief Calculate the GBCE all share index, this is the geometric mean of prices for all stocks
 * @param[in] begin Iterator to container of trades
 * @param[in] end Iterator to container of trades
 */
template <typename Iterator> double gbce_all_share_index(Iterator begin, Iterator end)
{
    return 0.0;
}
}