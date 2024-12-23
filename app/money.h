#pragma once
#include <istream>
#include <iostream>

namespace vsite::oop::v7 
{

    class money
    {
    private:
        int total;
    public:
        money(int eur = 0, int ct = 0) : total(eur * 100 + ct) { }
        money operator-(const money& m) const;
        money& operator-=(const money& m);
        money operator+(const money& m) const;
        money& operator+=(const money& m);
        friend std::istream& operator>>(std::istream& is, money& m);
        friend std::ostream& operator<<(std::ostream& os, money& m);

    };

}
