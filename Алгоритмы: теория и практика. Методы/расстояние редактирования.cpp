/*Вычислите расстояние редактирования двух данных непустых строк длины не более 10^2, содержащих строчные буквы латинского алфавита.*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool diff(char a, char b)
{
    if (a == b) return 0;
    else return 1;
}

int EditDistTD(string A, string B, int i, int j, vector<vector<int>>& D)
{
    if (D[i][j] == -1)
    {
        if (i == 0)
            D[i][j] = j;
        else if (j == 0)
            D[i][j] = i;
        else
        {
            int ins = EditDistTD(A, B, i, j - 1, D) + 1;
            int del = EditDistTD(A,B,i - 1, j, D) + 1;
            int sub = EditDistTD(A, B, i - 1, j - 1, D) + diff(A[i-1],B[j-1]);
            int temp = min(ins, del);
            D[i][j] = min(temp, sub);

        }
    }
    return D[i][j];
}

int main() {
    string str1, str2;
    cin >> str1 >> str2;
    int n = str1.size();
    int m = str2.size();
    int res;
    vector<vector<int> > a(n+1, vector<int>(m+1, -1)); 
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
            res = EditDistTD(str1, str2, i, j, a);
    }
    cout << res;

    return 0;
}