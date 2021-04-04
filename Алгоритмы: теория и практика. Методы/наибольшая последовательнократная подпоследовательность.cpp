/*Дано целое число 1≤n≤10^3 и массив A[1…n] натуральных чисел, не превосходящих 2⋅10^9. Выведите максимальное 1≤k≤n, для которого
найдётся подпоследовательность 1≤i_1<i_2<…<i_k≤n длины k, в которой каждый элемент делится на предыдущий.*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int LISBottomUp(vector<int> A, int n)
{
    vector<int> D(n);
    for (int i = 0; i < n; i++)
    {
        D[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (A[i] % A[j]==0 && D[j] + 1>D[i])
                D[i] = D[j] + 1;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
        ans = max(ans, D[i]);
    return ans;
}

int main() {
    int n; cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];
    cout << LISBottomUp(A, n);


    return 0;
}