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

    bool operator>>(std::istream& inputStream, money& m) {
        uint32_t k, l;
        inputStream >> k;
        inputStream >> l;
        m.lipe = (k * 100);
        m.lipe += l;
        return true;
    };

    std::ostream& operator<<(std::ostream &os, money &m) {
        os << std::format("{} kn, {:0>2} lp", m.lipe / 100, m.lipe % 100);
        return os;
    }

    void operator+=(money& rm, money& lm) {
        rm.lipe += lm.lipe;
    }

    void operator-=(money& rm, money& lm) {
        if (rm.lipe < lm.lipe)
            rm.lipe = 0;
        else rm.lipe -= lm.lipe;
    }

}