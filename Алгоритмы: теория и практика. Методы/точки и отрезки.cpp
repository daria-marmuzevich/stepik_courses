/*В первой строке задано два целых числа 1≤n≤50000 и 1≤m≤50000 — количество отрезков и точек на прямой, соответственно. 
Следующие n строк содержат по два целых числа a_i и b_i (a_i≤b _i) — координаты концов отрезков. Последняя строка содержит
m целых чисел — координаты точек. Все координаты не превышают 10^8 по модулю. Точка считается принадлежащей отрезку, 
если она находится внутри него или на границе. Для каждой точки в порядке появления во вводе выведите, скольким отрезкам она принадлежит.*/

#include <iostream>
#include <vector>
#include <cinttypes>
#include <ios>
using namespace std;

int get_pos1(const std::vector<int>& A, int number) {
    int l = 0, r = A.size() - 1, N=0;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (A[m] <= number)
        {
            N = m+1;
            l = m + 1;
        }
      
        else 
            r = m - 1;
    }
    return N;
}
int get_pos2(const std::vector<int>& A, int number) {
    int l = 0, r = A.size() - 1, M=0;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (A[m] < number)
        {
            M = m + 1;
            l = m + 1;
        }

        else
            r = m - 1;
    }
    return M;
}

int Partition(vector<int>& A, int l, int r, int& right)
{
    swap(A[l], A[(l + r) / 2]);
    int x = A[l];
    int j = l;
    
    for (int i = l + 1; i <= r; i++)
    {
        if (A[i] <= x)
        {
            j++;
            swap(A[j], A[i]);
        }
    }
    right = j;
    for (int i = l + 1; i <= j; i++)
    {
        if (A[i] == x)
        {
            swap(A[i], A[j]);
            j--;
        }
    }

    swap(A[l], A[j]);

    return j;
}

//void QuickSort(vector<int>& A, int l, int r)
//{
//    int right;
//    if (l >= r) return;
//    int m = Partition(A, l, r, right);
//    QuickSort(A, l, m - 1);
//    QuickSort(A, right+1, r);
//}

void QuickSort(vector<int>& A, int l, int r)
{

    int right;
    while (l < r)
    {
        int m = Partition(A, l, r, right);
        if (m - l <= r - right) {
            QuickSort(A, l, m - 1);
            l = right + 1;
        }
        else {
            QuickSort(A, right+1, r);
            r = m-1;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int n, m; cin >> n >> m;
  
    vector<int> points(m), beginp(n), endp(n);

    for (int i = 0; i < n; i++)
    {
        cin >> beginp[i] >> endp[i];
    }
  

    for (int i = 0; i < m; i++)
        cin >> points[i];

    QuickSort(beginp, 0, n - 1);
    QuickSort(endp, 0, n - 1);
    
    int M, N;
 

    for (int i = 0; i < m; i++)
    {
        N = get_pos1(beginp, points[i]);
        M = get_pos2(endp, points[i]);
        cout << N - M<<" ";
    }

    
    return 0;
}