#include <iostream>
using namespace std;

const int MOD = 10007;

// 각 자리수마다 0 ~ 9 까지 있으므로
int dp[10001][11];

int solve(int n, int num)
{
    if (n == 1)
    {
        return 1;
    }

    if (dp[n][num] > 0)
    {
        return dp[n][num];
    }

    for (int i = num; i <= 9; ++i)
    {
        dp[n][num] += solve(n - 1, i);
    }

    dp[n][num] %= MOD;

    return dp[n][num];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int n;
    cin >> n;

    int result = 0;
    for (int i = 0; i <= 9; ++i)
    {
        result += solve(n, i);
    }

    cout << result % MOD << "\n";

    return 0;
}
