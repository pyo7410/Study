#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<int, double> a, pair<int, double> b)
{
    if (a.second == b.second)
    {
        return a.first < b.first;
    }

    return a.second > b.second;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<int, double>> rate;

    sort(stages.begin(), stages.end());

    int stages_size = stages.size();
    int player_cnt = stages.size();
    int idx = 0;
    for (int i = 1; i <= N; ++i)
    {
        int cnt = 0;

        while (idx < stages_size && stages[idx] == i)
        {
            idx++;
            cnt++;
        }

        if (cnt == 0)
        {
            rate.push_back({i, 0});
        }
        else
        {
            rate.push_back({i, ((double)cnt / player_cnt)});
        }
        
        player_cnt -= cnt;
    }

    sort(rate.begin(), rate.end(), cmp);

    for (auto r : rate)
    {
        answer.push_back(r.first);
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

    int m;
    cin >> m;

    vector<int> stages(m);

    for (int i = 0; i < m; ++i)
    {
        cin >>stages[i];
    }

    solution(n, stages);

    return 0;
}