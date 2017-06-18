#pragma once

#include "stocks.h"
#include <set>

namespace stocks
{
/** @brief Functor to sort trades by timestamp */
struct sort_by_timestamp
{
    using is_transparent = void;

    bool operator()(trade const &lhs, trade const &rhs) const
    {
        return lhs.timestamp() < rhs.timestamp();
    }

    bool operator()(trade::timestamp_type const &lhs, trade const &rhs) const
    {
        return lhs < rhs.timestamp();
    }

    bool operator()(trade const &lhs, trade::timestamp_type const &rhs) const
    {
        return lhs.timestamp() < rhs;
    }
};

/** @brief The market class is a container of trades indexed by timestamp. (In a non toy example
 * this would be implemented using https://github.com/rbock/sqlpp11) */
using market = std::multiset<trade, sort_by_timestamp>;

}
