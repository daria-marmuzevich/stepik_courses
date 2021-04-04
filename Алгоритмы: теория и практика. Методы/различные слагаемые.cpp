/*По данному числу 1≤n≤10^9 найдите максимальное число k, для которого n можно 
представить как сумму k различных натуральных слагаемых. Выведите в первой строке 
число k, во второй — k слагаемых.*/

#include <iostream>
#include <vector>
using namespace std;
 
int main() {
    int number, temp(0),i(1); cin >> number;
    vector <int> slag(0);

    while ( number !=0)
    {
        if (number - i > i || number-i==0)
        {
            slag.push_back(i); number -= i; 
        }
        i++;

    }
    cout << slag.size() << endl;
    for (int i = 0; i < slag.size(); i++)
    {
        cout << slag[i] << " ";
    }
    
    return 0;
}