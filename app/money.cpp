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


    money& money::operator + (const money& m) {
        _total += m._total;

        return *this;
    }

    money& money::operator += (const money& m) {
        this->operator+(m);
        return *this;
    }


    money& money::operator - (const money& m) {
        _total -= m._total;

        return *this;
    }

    money& money::operator -= (const money& m) {
        this->operator-(m);
        return *this;
    }


    std::ostream& operator<<(std::ostream& os, const money& m) {
        return os << m.to_string();
    }

    std::istream& operator>>(std::istream& is, money& m) {
        int kn, lp;
        is >> kn >> lp;
        m._total = kn * 100 + lp;
        return is;
    }


    std::string money::to_string() const {
        if (kn() == 0)
        {
            return std::format("{:02d} lp", lp());
        }
        else if (lp() == 0)
        {
            return std::format("{} kn", kn());
        }
        else
        {
            return std::format("{} kn, {:02d} lp", kn(), lp());
        }
    }
}