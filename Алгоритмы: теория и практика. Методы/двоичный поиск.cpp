/*В первой строке даны целое число 1≤n≤10^5 и массив A[1…n] из n различных натуральных чисел, не превышающих 10^9, в порядке возрастания,
во второй — целое число 1≤k≤10^5 и k натуральных чисел b_1,..,b_k, не превышающих 10^9 . Для каждого i от 1 до k необходимо 
вывести индекс 1≤j≤n, для которого A[j]=b_i, или -1, если такого j нет.*/

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

int get_pos(const std::vector<int>& numbers, int number) {
    // TODO optimize this function 
    int l = 0, r = numbers.size();
    while (l+1 < r)
    {
        int m = l + (r - l) / 2;
        if (numbers[m] > number)
            r = m;
        else
            l = m ;
    }
    if (l==r || numbers[l] != number)
        return -1;
    return l + 1;
}

int main(void) {
    size_t number_count;
    std::cin >> number_count;
    std::vector<int> numbers(number_count);
    for (size_t i = 0; i < number_count; i++) {
        std::cin >> numbers[i];
    }

    size_t query_count;
    std::cin >> query_count;
    while (query_count-- > 0) {
        int number;
        std::cin >> number;
        std::cout << get_pos(numbers, number) << " ";
    }
    std::cout << std::endl;
}