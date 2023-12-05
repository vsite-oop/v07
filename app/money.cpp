#include "money.h"
#include <algorithm>
#include <format>

namespace vsite::oop::v7
{
    money::money(int lp) : _kn(lp / 100), _lp(lp % 100) { }

    money::money(int kn, int lp) : _kn(kn + lp / 100), _lp(lp % 100) { }

    money money::operator + (money m) {
        int val = (this->getIntAmount() + m.getIntAmount());
        _kn = val / 100;
        _lp = val % 100;

        return *this;
    }

    money money::operator += (money m) {
        this->operator+(m);
        return *this;
    }


    money money::operator - (money m) {
        int val = (this->getIntAmount() - m.getIntAmount());
        _kn = val / 100;
        _lp = val % 100;

        return *this;
    }

    money money::operator -= (money m) {
        this->operator-(m);
        return *this;
    }


    std::ostream& operator<<(std::ostream& os, const money& m) {
        return os << "Kuna: " << m._kn << " Lipa: " << m._lp << "\n";
    }

    std::istream& operator>>(std::istream& is, money& m)
    {
        is >> m._kn >> m._lp;
        return is;
    }


    int money::getIntAmount() const
    {
        return _kn * 100 + _lp;
    }

    std::string money::to_string() {
        if (_kn == 0)
        {
            return std::format("{:02d} lp", _lp);
        }
        else
        {
            return std::format("{} kn, {:02d} lp", _kn, _lp);
        }
    }
}