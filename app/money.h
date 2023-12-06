#include <ostream>
#include <iostream>
#include <string>

namespace vsite::oop::v7
{
    class money {
        int _total;

    public:
        money(int kn = 0, int lp = 0);

        int kn() const;

        int lp() const;
        
        money& operator + (const money& m);
        money& operator += (const money& m);
             
        money& operator - (const money& m);
        money& operator -= (const money& m);

        std::string to_string() const;
        
        friend std::ostream& operator<<(std::ostream& os, const money& m);
        friend std::istream& operator>>(std::istream& is, money& m);
    };
}


