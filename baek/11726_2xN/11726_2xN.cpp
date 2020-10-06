#include <iostream>
#include <cstring>
#include <algorithm>
#define MOD 10007
using namespace std;

int dp[1001];

int solve(int start)
{
    // 1이하라는 것은 사각형을 다 덮었다는 의미
    if (start <= 1)
    {
        return 1;
    }

    if (dp[start] > 0)
    {
        return dp[start];
    }

    dp[start] = solve(start - 1) % MOD + solve(start - 2) % MOD;

    return dp[start];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int n;
    cin >> n;

    cout << solve(n) % MOD << "\n";

    return 0;
}
