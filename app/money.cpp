#include "money.h"
#include <algorithm>
#include <format>

namespace vsite::oop::v7
{
    money::money(int eur, int cent) : _total(eur * 100 + cent) { }

    int money::eur() const {
        return _total / 100;
    }

    int money::cent() const {
        return _total % 100;
    }


    money money::operator + (const money& m) const {
        money r;
        r._total = _total + m._total;

        return r;
    }

    money& money::operator += (const money& m) {
        _total += m._total;

        return *this;
    }


    money money::operator - (const money& m) const {
        money r;
        r._total = _total - m._total;

        return r;
    }

    money& money::operator -= (const money& m) {
        _total -= m._total;

        return *this;
    }


    std::ostream& operator<<(std::ostream& os, const money& m) {
        if (m.eur() == 0)
        {
            return os << std::format("{:02d} cent", m.cent());
        }
        else if (m.cent() == 0)
        {
            return os << std::format("{} eur", m.eur());
        }
        else
        {
            return os << std::format("{} eur, {:02d} cent", m.eur(), m.cent());
        }
    }

    std::istream& operator>>(std::istream& is, money& m) {
        int eur, cent;
        is >> eur >> cent;
        m._total = eur * 100 + cent;
        return is;
    }
}