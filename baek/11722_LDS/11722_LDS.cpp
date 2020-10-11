#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
int arr[1001];
int dp[1001];

int solve(int x)
{
    if (dp[x] != -1)
    {
        return dp[x];
    }

    dp[x] = 1;

    for (int i = x + 1; i < n; ++i)
    {
        if (arr[x] > arr[i])
        {
            dp[x] = max(dp[x], solve(i) + 1);
        }
    }

    return dp[x];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    memset(dp, -1, sizeof(dp));

    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    int result = 0;
    for (int i = 0; i < n; ++i)
    {
        result = max(result, solve(i));
    }

    cout << result << "\n";

    return 0;
}