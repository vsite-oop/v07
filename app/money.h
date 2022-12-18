#pragma once
#include <iostream>

namespace vsite::oop::v7 
{

class money {
    uint32_t lipe;
    friend std::istream& operator>>(std::istream&, money&);
    friend std::ostream& operator<<(std::ostream&, const money&);
public:
    money();
    money(uint32_t const kuna, uint32_t const lipa = 0);
    ~money() = default;
    money& operator+=(const money&);
    money& operator-=(const money&);
};

}
