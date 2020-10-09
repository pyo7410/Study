#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int N;
int arr[1001];
int dp[1001];

int solve(int n)
{
    if (dp[n] != -1)
    {
        return dp[n];
    }

    // 시작점은 존재하므로
    dp[n] = 1;

    for (int i = n + 1; i < N; ++i)
    {
        if (arr[n] < arr[i])
        {
            // 이미 dp가 계산됬을 수 도 있으므로
            dp[n] = max(dp[n], solve(i) + 1);
        }
    }

    return dp[n];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        cin >> arr[i];
    }

    memset(dp, -1, sizeof(dp));

    int result = 0;
    for (int i = 0; i < N; ++i)
    {
        result = max(result, solve(i));
    }

    cout << result << "\n";

    return 0;
}