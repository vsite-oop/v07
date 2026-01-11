#pragma once

namespace vsite::oop::v6
{

    template <typename T>
    T minimum(T a, T b) {
        if (a < b)
            return a;
        return b;
    }

    template <typename T, int N>
    class fixed_array {
    private:
        T arr[N];
    public:
        unsigned long long size() {
            return N;
        }

        T& operator[](int index) {
            return arr[index];
        }
    };

    template <typename T>
    struct point {
        T x;
        T y;
    };
}
