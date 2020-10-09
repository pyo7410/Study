#include <iostream>
#include <cstring>
using namespace std;

int dp[1000];

int solve(int n)
{
    // 0 보다 작은 수는 1, 2, 3의 합으로 못 나타내므로
    if (n < 0)
    {
        return 0;
    }

    // 1, 2, 3으로 표현해야하므로 0, 1 은 각각 1번의 수가 된다.
    if (n <= 1)
    {
        return 1;
    }

    // 한번 계산된 적이 있다면
    if (dp[n] > 0)
    {
        return dp[n];
    }

    dp[n] = solve(n - 1) + solve(n - 2) + solve(n - 3);

    return dp[n];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        memset(dp, 0, sizeof(dp));

        cout << solve(n) << "\n";
    }

    return 0;
}