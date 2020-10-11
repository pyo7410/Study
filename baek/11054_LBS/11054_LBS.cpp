#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
int arr[1001];
int dp[1001];
int r_dp[1001];

int solve(int x)
{
    if (dp[x] != -1)
    {
        return dp[x];
    }

    dp[x] = 1;

    for (int i = x + 1; i < n; ++i)
    {
       if (arr[x] < arr[i])
       {
           dp[x] = max(dp[x], solve(i) + 1);
       }
    }

    return dp[x];
}

int reverse_solve(int x)
{
    if (r_dp[x] != -1)
    {
        return r_dp[x];
    }

    r_dp[x] = 1;

    for (int i = x - 1; i >= 0; i--)
    {
       if (arr[x] < arr[i])
       {
           r_dp[x] = max(r_dp[x], solve(i) + 1);
       }
    }

    return r_dp[x];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    memset(dp, -1, sizeof(dp));
    memset(r_dp, -1, sizeof(r_dp));

    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    int result = 0;
    for (int i = 0; i < n; ++i)
    {
        result = max(result, solve(i) + reverse_solve(n - i - 1)  - 1);
    }

    cout << result << "\n";

    return 0;
}