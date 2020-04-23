#include <iostream>
#include <vector>
using namespace std;

int n;
int s[20][20];

int go(int index, vector<int>& first, vector<int>& second)
{
    int team_1 = 0;
    int team_2 = 0;
    int ans = -1;
    int diff;

    if (index == n)
    {   // first와 second는 어차피 n / 2만큼 들어있으므로 2로 나눠줄 필요가 없어.... 왜그래...
        if (first.size() != n / 2)
        {
            return -1;
        }
        if (second.size() != n / 2)
        {
            return -1;
        }

        // n / 2 인 이유는 각 팀마다 n / 2명의 인원만 있기 때문이다
        for (int i = 0; i < n / 2; ++i)
        {
            for (int j = 0; j < n / 2; ++j)
            {
                if (i == j)
                {
                    continue;
                }
                team_1 += s[first[i]][first[j]];
                team_2 += s[second[i]][second[j]];
            }
        }
        diff = team_1 - team_2;
        if (diff < 0)
        {
            diff = -diff;
        }
        return diff;
    }

    // n / 2 만큼 채웠다면 더이상 채울 필요가 없기 때문이다
    if (first.size() > n / 2)
    {
        return -1;
    }
    if (second.size() > n / 2)
    {
        return -1;
    }
    
    first.push_back(index);
    team_1 = go(index + 1, first, second);

    // ans == -1 인 경우는 무조건 최소값을 넣어 주어야 하기 때문이다.
    if (ans == -1 || (team_1 != -1 && ans > team_1)) // ans는 최소값을 찾는 문제이다
    {
        ans = team_1;
    }

    first.pop_back(); // second팀의 경우도 구해야하기 때문이다.

    second.push_back(index);
    team_2 = go(index + 1, first, second);

    if (ans == -1 || (team_2 != -1 && ans > team_2)) // ans는 최소값을 찾는 문제이다
    {
        ans = team_2;
    }
    second.pop_back();

    return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> n;

    vector<int> first, second;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> s[i][j];
        }
    }

    cout << go(0, first, second) << "\n";

    return 0;
}
