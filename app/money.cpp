#include "money.h"
#include<format>
#include<iomanip>


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
            os << std::setw(2) << std::setfill('0') << m.lp() << " lp";
        }
        else if (m.lp() == 0)
        {

            os << std::setw(2) << std::setfill('0') << m.kn() << " kn";
        }

        else
        {
            os << m.kn() << " kn, " << std::setw(2) << std::setfill('0') << m.lp() << " lp";
        }
        return os;

    }

    std::istream& operator>>(std::istream& is, money& m) {
        int kn, lp;
        if (is >> kn >> lp) {
            m = money(kn, lp);
        }

        return is;
    }

}