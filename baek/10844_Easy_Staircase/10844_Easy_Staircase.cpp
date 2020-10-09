#include <iostream>
#include <cstring>
using namespace std;

// ? ???? ?? ??? ?????? ??
long long dp[101][10];
long long MOD = 1000000000LL;

long long solve(int n, int num)
{
    if (n == 1)
    {
        // 0?? ???? ??? ??.
        if (num == 0)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }

    if (dp[n][num] > 0)
    {
        return dp[n][num];
    }

    if (num - 1 >= 0)
    {
        // ???? ?? ???? ???? ???.
        dp[n][num] += solve(n - 1, num - 1);
    }
    if (num + 1 <= 9)
    {
        // ???? ?? ??? ???? ???.
        dp[n][num] += solve(n - 1, num + 1);
    }

    dp[n][num] %= MOD;

    return dp[n][num];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    memset(dp, 0, sizeof(dp));

    int n;
    cin >> n;

    long long result = 0;

    for (int i = 0; i <= 9; ++i)
    {
        result += solve(n, i);
    }

    cout << result % MOD << "\n";

    return 0;
}