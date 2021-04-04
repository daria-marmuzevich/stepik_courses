/*По данным n отрезкам необходимо найти множество точек минимального 
размера, для которого каждый из отрезков содержит хотя бы одну из точек.
В первой строке дано число 1≤n≤100 отрезков. Каждая из последующих 
n строк содержит по два числа 0 0≤l≤r≤10^9, задающих начало и конец отрезка.
Выведите оптимальное число m точек и сами m точек. Если таких множеств точек 
несколько, выведите любое из них.*/

#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

typedef std::pair <int, int> Segment;

void sortfunc(std::vector <Segment>& a)
{
    
    for (int i = 0; i < a.size(); i++)
    {
        for (int arrIndex = 0; arrIndex < a.size() - 1; arrIndex++)
        {
            if (a[arrIndex].second > a[arrIndex + 1].second)
            {
                swap(a[arrIndex], a[arrIndex + 1]);
            }
        }
    }
}



std::vector <int> get_covering_set(std::vector <Segment> segments) {
    std::vector <int> result;
    
    std::vector <int> Massiv(0, 0);
    int size = -1, c=0; 
 
    sortfunc(segments);
    int temp = 0;
    for (std::size_t i = 0; i < segments.size(); i++) {
        if (i > 0)
        {
            for (int t = 0; t < c; t++) {
                if (i == Massiv[t]) {
                    temp++;
                    break;
                }
            }
        }
        if (temp==0)
        {
          result.push_back(segments[i].second);
          size++;
          for (std::size_t j = 0; j < segments.size(); j++)
          {
             if (result[size] >= segments[j].first && result[size] <= segments[j].second) 
             {
              Massiv.push_back(j); c++;
             }
          }
        }
        temp = 0;
    }
    
    return result;
}

int main(void) {
    int segments_count;
    std::cin >> segments_count;
    std::vector <Segment> segments(segments_count);
    for (int i = 0; i < segments_count; i++) {
        std::cin >> segments[i].first >> segments[i].second;
    }

    std::vector <int> points = get_covering_set(segments);
    std::cout << points.size() << std::endl;
    for (std::size_t i = 0; i < points.size(); i++) {
        std::cout << points[i] << " ";
    }
    std::cout << std::endl;
    system("pause");
}