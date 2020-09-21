#include <iostream>
#include <queue>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, x;
    cin >> n;

    priority_queue<int, vector<int>, less<int>> pq;
    for (int i = 0; i < n; ++i)
    {
        cin >> x;

        if (x == 0)
        {
            if (!pq.empty())
            {
                cout << pq.top() << "\n";
                pq.pop();
            }
            else
            {
                cout << 0 << "\n";
            }
        }
        else
        {
            pq.push(x);
        }
    }

    return 0;
}