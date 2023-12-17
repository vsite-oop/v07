#include "money.h"
#include <algorithm>
#include <format>


namespace vsite::oop::v7
{
    money::money(int kn, int lp) : _total(kn * 100 + lp) { }

    int money::kn() const {
        return _total / 100;
    }

    int money::lp() const {
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
        if (m.kn() == 0)
        {
            return os << std::format("{:02d} lp", m.lp());
        }
        else if (m.lp() == 0)
        {
            return os << std::format("{} kn", m.kn());
        }
        else
        {
            return os << std::format("{} kn, {:02d} lp", m.kn(), m.lp());
        }
    }

    std::istream& operator>>(std::istream& is, money& m) {
        int kn, lp;
        is >> kn >> lp;
        m._total = kn * 100 + lp;
        return is;
    }
}