#pragma once
#include <ostream>
#include <iostream>
#include <string>

namespace vsite::oop::v7
{
    class money {
        int _total;

    public:
        money(int eur = 0, int cent = 0);

        int eur() const;

        int cent() const;

        money operator + (const money& m) const;
        money& operator += (const money& m);

        money operator - (const money& m) const;
        money& operator -= (const money& m);

        friend std::ostream& operator<<(std::ostream& os, const money& m);
        friend std::istream& operator>>(std::istream& is, money& m);
    };
}