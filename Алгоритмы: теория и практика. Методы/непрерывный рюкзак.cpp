/*Первая строка содержит количество предметов 1≤n≤10^3 и вместимость рюкзака 0≤W≤2⋅10^6.
Каждая из следующих n строк задаёт стоимость 0≤c_i≤2⋅10^6 и объём 0<w_i≤2⋅10^6 предмета. 
Выведите максимальную стоимость частей предметов (от каждого предмета можно отделить любую часть, 
стоимость и объём при этом пропорционально уменьшатся), помещающихся в данный рюкзак, с точностью не менее 
трёх знаков после запятой.*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cinttypes>
#include <ios>
using namespace std;
 
struct object
{
    double c;
    double w;
};

bool my_pair_sort1(object s1, object s2) {
    return static_cast<int64_t>(s1.w)*s2.c < static_cast<int64_t>(s2.w)*s1.c;
}


int main() 
{
    cout << fixed << setprecision(3);
    ios_base::sync_with_stdio(false);

    int n; double wr, result=0; 
    cin >> n >> wr;
    vector <object> items(n);
    for (int i = 0; i < n; i++) {
        cin >> items[i].c >> items[i].w;
    }
    sort(items.begin(), items.end(), my_pair_sort1);
    for (int temp = 0; temp < n; temp++)
    {
        if (items[temp].w < wr)
        {
            result += items[temp].c;
            wr = wr - items[temp].w;
        }
        else {
            result+=items[temp].c* wr/items[temp].w;
            break;
        }
    }
    cout << result;

    return 0;
}