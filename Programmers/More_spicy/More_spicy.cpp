#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

struct cmp
{
    bool operator()(pair<int, int> p1, pair<int, int> p2)
    {
        return p1.second < p2.second;
    }

};

int solution(vector<int> scoville, int K)
{
    int answer = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;

    for (int i = 0; i < scoville.size(); ++i)
    {
        pq.push(make_pair(i, -scoville[i]));
    }

    while (!pq.empty())
    {
        if (-(pq.top().second) < K)
        {
            if (pq.size() == 1)
            {
                return -1;
            }

            answer++;
            int i = pq.top().first;
            int mix = -(pq.top().second);
            pq.pop();
            int j = pq.top().first;
            mix += (-(pq.top().second) * 2);
            pq.pop();

            pq.push(make_pair(i, -mix));
        }
        else
        {
            pq.pop();
        }
    }

    return answer;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    int n;
    cin >> n;

    vector<int> scoville(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> scoville[i];
    }

    int k;
    cin >> k;

    cout << solution(scoville, k) << "\n";

    return 0;
}