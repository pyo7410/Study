#include <iostream>
#include <queue>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, a;
    cin >> n;

    priority_queue<int, vector<int>, less<int>> pq;
    for (int i = 0; i < n; ++i)
    {
        cin >> a;
        
        if (a == 0)
        {
            if (pq.empty())
            {
                cout << -1 << "\n";
                continue;
            }
            else
            {
                cout << pq.top() << "\n";
                pq.pop();   
            }
        }
        else
        {
            int gift;
            for (int j = 0; j < a; ++j)
            {
                cin >> gift;
                pq.push(gift);
            }
        }
    }

    return 0;
}