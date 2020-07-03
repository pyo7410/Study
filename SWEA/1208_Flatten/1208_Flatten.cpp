#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int main()
{
    for (int i = 1; i <= 10; ++i)
    {
        int dump;
        cin >> dump;
 
        vector<int> box(100);
 
        for (int i = 0; i < 100; ++i)
        {
            cin >> box[i];
        }
 
        int max_idx;
        int min_idx;
        while (dump--)
        {
            max_idx = max_element(box.begin(), box.end()) - box.begin();
            min_idx = min_element(box.begin(), box.end()) - box.begin();
 
            box[max_idx] -= 1;
            box[min_idx] += 1;
        }
 
        max_idx = max_element(box.begin(), box.end()) - box.begin();
        min_idx = min_element(box.begin(), box.end()) - box.begin();
 
        cout << "#" << i << " " << box[max_idx] - box[min_idx] << "\n";
    }
 
    return 0;
}