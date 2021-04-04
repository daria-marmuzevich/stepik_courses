/*ѕо данной непустой строке s длины не более 10^4, состо€щей из строчных букв латинского алфавита, 
постройте оптимальный беспрефиксный код. ¬ первой строке выведите количество различных букв k, 
встречающихс€ в строке, и размер получившейс€ закодированной строки. ¬ следующих k строках запишите 
коды букв в формате "letter: code". ¬ последней строке выведите закодированную строку.*/

#include <iostream>
#include <string>
#include<algorithm>
#include <map>
#include <set>
#include <vector>
using namespace std;



int main() {
    string s, s0; cin >> s;
    int k = 0; 
    set <pair<string, int>> sset;
    set<pair< int, string>> svec;

    vector<pair<string, string>> snew;
    vector<pair<string, string>> skod;
  
    
    
    for (int i = 0; i < s.size(); i++)
    {
        for (int j = 0; j < s.size(); j++)
        {
            if (s[i] == s[j]) k++;
        }
        s0 = s[i];
        sset.insert(pair<string, int>(s0, k));
        sset.emplace(s0, k);
        k = 0;
    }
   
    for (auto it = sset.begin(); it != sset.end(); ++it)
    {
        svec.emplace(it->second, it->first);
    }
   
    auto it1 = svec.begin();
    auto it2 = svec.begin(); ++it2;
    int size = svec.size();
    if (size==1) snew.push_back(pair<string, string>(it1->second, "0"));

    for (int i=1; i<size; i++)
    {
       
        string first1 = it1->second; 
        int second1 = it1->first;
        string first2=  it2->second;
        int second2 = it2->first;
        svec.erase(it1);
        svec.erase(it2);
        
        int t = second1 + second2;
        string s = first1 + first2;
       svec.emplace(t, s);


       it1 = svec.begin();
       it2 = svec.begin(); it2++;


        snew.push_back(pair<string, string>(first1, "0"));
        snew.push_back(pair<string, string>(first2, "1"));
    }

    int tmp = 0, j=0;
    for (auto iter = sset.begin(); iter != sset.end(); iter++)
    {
        string a = iter->first; //s.find(a)
        for (int i = snew.size()-1; i >=0; i--)
        {
            string b = snew[i].first;
            if (b.find(a) != -1)
            {
                if (tmp == 0) {
                    skod.push_back(pair<string, string>(a, snew[i].second));
                    tmp++;
                }
                else
                {
                    skod[j].second += snew[i].second;
                }
            }
       

        }
        tmp = 0;
        j++;
    }

    
   

    int count = 0; string h = "";
    for (int i(0); i < s.size(); i++)
    {
        s0 = s[i];
        for (auto it=skod.begin(); it!=skod.end(); it++)
        {
            if (s0 == it->first) {
                
                string h0= it->second;
                h += h0;
                count += h0.size();
                break;
            }
        }
    }
    cout << sset.size() << " " << count<<endl;
    for (auto it = skod.begin(); it != skod.end(); ++it)///вывод на экран
    {
        cout << it->first << ": " << it->second << endl;
    }
    cout << h<<endl;

    system("pause");
    return 0;
}‘