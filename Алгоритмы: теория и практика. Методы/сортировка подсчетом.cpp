/*Первая строка содержит число 1≤n≤10^4, вторая — n натуральных чисел, не превышающих 10. 
Выведите упорядоченную по неубыванию последовательность этих чисел.*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> CountSort(vector<int> A, int n)
{
    vector<int> B(10, 0);
    vector<int> A1(n);
    for (int j = 0; j < n; j++)
        B[A[j]-1] += 1;
    for (int i = 1; i < 10; i++)
        B[i] += B[i - 1];
    for (int j = n - 1; j >= 0; j--) {
        A1[B[A[j]-1]-1] = A[j];
        B[A[j]-1] -= 1;
    }
    return A1;
}

int main() {
    int n; cin >> n;
    vector<int> A(n), A1(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];
    A1 = CountSort(A, n);
    for (int i = 0; i < n; i++)
        cout << A1[i] << ' ';
    return 0;
}