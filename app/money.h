#include <ostream>
#include <iostream>
#include <string>

namespace vsite::oop::v7
{
    class money {
        int _kn;
        int _lp;

    public:
        money(int lp = 0);
        money(int kn, int lp);
        
        money operator + (money m);
        money operator += (money m);

        money operator - (money m);
        money operator -= (money m);

        int getIntAmount() const;

        std::string to_string();
        
        friend std::ostream& operator<<(std::ostream& os, const money& m);
        friend std::istream& operator>>(std::istream& is, money& m);
    };
}


