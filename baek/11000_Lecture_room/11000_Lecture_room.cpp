#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    int s, t;
    vector<vector<int>> classes(n, vector<int>(2));
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < n; ++i)
    {
        cin >> s >> t;

        classes[i][0] = s;
        classes[i][1] = t;
    }

    sort(classes.begin(), classes.end());
    pq.push(classes[0][1]);

    int start, end;
    for (int i = 1; i < n; ++i)
    {
        start = classes[i][0];
        end = classes[i][1];

        if (pq.top() > start)
        {
            // 수업중인 강의실의 끝나는 시간을 push
            pq.push(end);
        }
        else
        {
            pq.pop();
            pq.push(end);
        }
    }
   
    cout << pq.size() << "\n";

    return 0;
}