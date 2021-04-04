/*По данным двум числам 1≤a,b≤2⋅10^9 найдите их наибольший общий делитель.*/
#include <cassert>
#include <iostream>


template <class Int>
Int gcd(Int a, Int b) {

    assert(a > 0);
    if (b > 0)
        return gcd(b, a % b);
    return a;
}

int main(void) {
    int a, b;
    std::cin >> a >> b;
    assert(a > 0 && b > 0);
    std::cout << gcd(a, b) << std::endl;
    return 0;
}