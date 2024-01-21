#include <ostream>
#include <iostream>
#include <string>

namespace vsite::oop::v7 
{

class money {

    int _total;

    int kn() const;

    int lp() const;

public:
    money(int kn = 0, int lp = 0);

    money operator + (const money& m) const;
    money& operator += (const money& m);

    money operator - (const money& m) const;
    money& operator -= (const money& m);

    friend std::ostream& operator<<(std::ostream& os, const money& m);
    friend std::istream& operator>>(std::istream& is, money& m);

};

}
