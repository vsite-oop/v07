#pragma once
#include <iostream>

namespace vsite::oop::v7 
{

class money {
    uint32_t lipe;
    friend bool operator>>(std::istream&, money&);
    friend std::ostream& operator<<(std::ostream&, money&);
    friend void operator+=(money&, money&);
    friend void operator-=(money&, money&);
public:
    money();
    money(uint32_t const kuna, uint32_t const lipa = 0);
    ~money() = default;
};

}
