#include <iostream>
#include <vector>
using namespace std;

int dp[100001][4];

int solution(vector<vector<int>> land)
{
    int answer = 0;
    int height = land.size();

    for (int i = 0; i < 4; ++i)
    {
        dp[0][i] = land[0][i];
    }

    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            for (int k = 0; k < 4; ++k)
            {
                if (j != k)
                {
                    dp[i][j] = max(dp[i][j], dp[i - 1][k] + land[i][j]);
                }
            }
        }
    }

    for (int i = 0; i < 4; ++i)
    {
        answer = max(answer, dp[height - 1][i]);
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

    vector<vector<int>> land(n, vector<int>(4));

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            cin >> land[i][j];
        }
    }

    cout << solution(land) << "\n";

    return 0;
}