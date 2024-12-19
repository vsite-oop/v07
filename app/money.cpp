#include "money.h"
#include <algorithm>

namespace vsite::oop::v7
{
    money money::operator-(const money& m) const
    {
        money x;
        x.total = total - m.total;
        return x;
    }

    money& money::operator-=(const money& m)
    {
        total -= m.total;
        return *this;
    }

    money money::operator+(const money& m) const
    {
        money x;
        x.total = total + m.total;
        return x;
    }

    money& money::operator+=(const money& m)
    {
        total += m.total;
        return *this;
    }

    std::istream& operator>>(std::istream& is, money& m)
    {
        int eur, ct;
        is >> eur >> ct;
        m.total = eur * 100 + ct;
        return is;
    }

    std::ostream& operator<<(std::ostream& os, money& m)
    {
        os << m.total / 100 << " eur, " << m.total % 100 << " ct";
        return os;
    }
}