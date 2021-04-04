/*Первая строка входа содержит число операций 1≤n≤10^5. Каждая из последующих n строк задают операцию одного из следующих двух типов:
Insert x, где 0≤x≤10^9 — целое число; ExtractMax.
Первая операция добавляет число x в очередь с приоритетами, вторая — извлекает максимальное число и выводит его.*/

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <stdio.h>
#include <string>
#include <algorithm>
using namespace std;

string s = "";
void Insert(int elem, vector<int>& tree)
{
    //  elem = (-1) * elem;
    int i = 0;
    if (tree.empty())
    {
        tree.push_back(elem);
    }
    else
    {
        tree.push_back(elem);
        i = tree.size();
        while (tree[i - 1] < tree[i / 2 - 1]) {


            swap(tree[i / 2 - 1], tree[i - 1]);
            i = i / 2;
            if (i == 1 || i == 0) break;

        }

    }
}

void ExtractMax(vector<int>& tree, vector<int>& rez)
{
    int i = 0;
    int size = tree.size();
    int min1, k = 0;
    if (size == 1)
    {
      
        rez.push_back((-1) * tree[0]);
        tree.pop_back();
    }
   
    else
    {
        
        rez.push_back((-1) * tree[0]);
        tree[0] = tree[size - 1];
        tree.pop_back();
        while (2 * i + 2 < size) {    // heapSize — количество элементов в куче
            int left = 2 * i + 1;       // left — левый сын
            int right = 2 * i + 2;         // right — правый сын
            int j = left;
            if (right < size - 1 && tree[right] < tree[left])
                j = right;
            if (tree[i] < tree[j])
                break;
            swap(tree[i], tree[j]);
            i = j;

        }


    }

}

int main() {
    vector<int> tree;
    vector <int> rez;
    int k, num; cin >> k;
    string str;
    char b = 'I';
    char A = 'E';
    for (int j = 0; j < k; j++)
    {
        cin >> str;
        if (str == "Insert") {
            cin >> num; Insert((-1) * num, tree);
        }
        else  ExtractMax(tree, rez);
    }

    for (int h = 0; h < rez.size(); h++) cout << rez[h] << endl;
    return 0;
}