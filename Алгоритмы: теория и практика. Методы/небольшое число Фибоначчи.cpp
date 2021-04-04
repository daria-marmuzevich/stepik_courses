/*Дано целое число 1≤n≤40, необходимо вычислить n-е число Фибоначчи */

//#include <cassert>
//#include <iostream>
//#include <unordered_map>
//#include <vector>
//
//class Fibonacci {
//public:
//    static int get(int n) {
//        assert(n >= 0);
//       /* double* mas = new double[n+1];
//        mas[0] = 0;
//        mas[1] = 1;
//        for (int i(2); i <= n; i++)
//            mas[i] = mas[i - 1] + mas[i - 2];
//        return mas[n];*/
//
//        if (n == 0 || n == 1) return n;
//        //static std::unordered_map<int, int> cache;
//
//        ///*auto& result = cache[n];
//        //if (result == 0)
//        //{
//        //    result = get(n - 2) + get(n - 1);
//        //}
//        //return result;*/
//
//        //for (int i = 2; i <= n; i++)
//        //    cache[i] = cache[i - 1] + cache[i - 2];
//        //return cache[n];
//
//        /*static std::vector <int> cache;
//        cache.resize(n + 1);
//        for (int i = 2; i <= n; i++)
//            cache[i] = cache[i - 1] + cache[i - 2];
//        return cache[n];*/
//
//        int previous = 0;
//        int current = 1;
//        for (int i = 2; i <= n; i++)
//        {
//            int new_current = previous + current;
//            previous = current;
//            current = new_current;
//        }
//        return current;
//
//    }
//};
//
//int main(void) {
//    int n;
//    std::cin >> n;
//    std::cout << Fibonacci::get(n) << std::endl;
//    return 0;
//}
