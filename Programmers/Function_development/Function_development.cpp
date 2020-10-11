#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

using pii = pair<int, int>;

vector<int> solution(vector<int> progresses, vector<int> speeds)
{
    vector<int> answer;
    int progresses_size = progresses.size();

    // first : progress, second : speed
    queue<pii> q;

    for (int i = 0; i < progresses_size; ++i)
    {
        q.push({progresses[i], speeds[i]});
    }

    while (!q.empty())
    {
        int cnt = 0;
        bool chk = false;

        if (q.front().first >= 100)
        {
            while (!q.empty() && q.front().first >= 100)
            {
                q.pop();
                cnt++;
            }

            answer.push_back(cnt);

            continue;
        }

        for (int i = 0; i < q.size(); ++i)
        {
            int progress = q.front().first;
            int speed = q.front().second;

            q.pop();
            q.push({progress + speed, speed});
        }
    }

    return answer;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    vector<int> progresses(n);
    vector<int> speeds(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> progresses[i];
    }

    for (int i = 0; i < n; ++i)
    {
        cin >> speeds[i];
    }

    solution(progresses, speeds);

    return 0;
}