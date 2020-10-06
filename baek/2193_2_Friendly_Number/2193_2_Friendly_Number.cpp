#include <iostream>
using namespace std;

// 각 자리수 마다 0과 1이 있으므로
long long dp[91][2];

long long solve(int n, int num)
{
    if (n == 1)
    {
        // 한 자리일때
        if (num == 0)
        {
            // 첫 시작이 0이라면
            // 0 을 리턴
            return 0;
        }
        else
        {
            // 첫 시작이 1이라면
            // 이친수이므로 1을 리턴
            return 1;
        }
    }

    if (dp[n][num] > 0)
    {
        return dp[n][num];
    }

    if (num == 0)
    {
        dp[n][num] = solve(n - 1, 0) + solve(n - 1, 1);
    }
    else if (num == 1)
    {
        dp[n][num] = solve(n - 1, 0);
    }

    return dp[n][num];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int n;
    cin >> n;

    long long result = 0;
    for (int i = 0; i < 2; ++i)
    {
        result += solve(n, i);
    }

    cout << result << "\n";

    return 0;
}
