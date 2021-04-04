/*Первая строка входа содержит целые числа 1≤W≤10^4 и 1≤n≤300 — вместимость рюкзака и число золотых слитков. 
Следующая строка содержит n целых чисел 0≤w_1,…,w_n≤10^5, задающих веса слитков. Найдите максимальный вес золота, 
который можно унести в рюкзаке.*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int KnapsackWithoutRepsBU(int W, int n, vector<int> weight_sl)
{
    vector<vector<int>> D(W + 1, vector<int>(n + 1));
    for (int w = 0; w <= W; w++)
        D[w][0] = 0;
    for (int i = 0; i <= n; i++)
        D[0][i] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int w = 1; w <= W; w++) {
            D[w][i] = D[w][i - 1];
            int wi = weight_sl[i];
            if (wi <= w)
                D[w][i] = max(D[w][i], D[w - wi][i - 1] + wi);
        }
    }
    return D[W][n];
}

int main() {
    int W, n;
    cin >> W >> n;
    vector<int> weight_slitkov(n+1);
    weight_slitkov[0] = 0;
    for (int i = 1; i <= n; i++)
        cin >> weight_slitkov[i];
    cout << KnapsackWithoutRepsBU(W, n, weight_slitkov);

    return 0;
}