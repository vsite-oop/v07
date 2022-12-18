#include "money.h"
#include <algorithm>
#include <iostream>
#include <string>
#include <format>


namespace vsite::oop::v7
{
    money::money() {
        lipe = 0;
    }

    money::money(uint32_t const k, uint32_t const l){
        lipe = k * 100;
        lipe += l;
    };

    std::istream& operator>>(std::istream& inputStream, money& m) {
        uint32_t k, l;
        inputStream >> k;
        inputStream >> l;
        m.lipe = (k * 100);
        m.lipe += l;
        return inputStream;
    };

    std::ostream& operator<<(std::ostream &os, const money &m) {
        auto k = m.lipe / 100;
        auto l = m.lipe % 100;
        if (k) os << k << " kn";
        if (k && l) os << ", ";
        if (l) os << std::format("{:0>2} lp", l);
        if (!k && !l) os << "No cash";
        return os;
    }

    money& money::operator+=(const money& lm) {
        lipe += lm.lipe;
        return *this;
    }

    money& money::operator-=(const money& lm) {
        if (lipe < lm.lipe)
            lipe = 0;
        else lipe -= lm.lipe;
        return *this;
    }

}