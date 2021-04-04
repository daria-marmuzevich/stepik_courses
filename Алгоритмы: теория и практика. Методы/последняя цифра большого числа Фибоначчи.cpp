/*Дано число 1≤n≤10^7, необходимо найти последнюю цифру n-го числа Фибоначчи.*/

#include <cassert>
#include <iostream>

class Fibonacci {
public:
    static int get_last_digit(int n) {
        assert(n >= 1);
        int a=0, b=1;
        for (int i=2; i < n; i++)
        {
            if(i%2==0)
            a = (a + b)%10;
            else 
            b = (b + a)%10;
        }

        n = (a + b) % 10;
        
        return n;
    }
};

int main(void) {
    int n;
    std::cin >> n;
    std::cout << Fibonacci::get_last_digit(n) << std::endl;
    system("pause");
    return 0;
}