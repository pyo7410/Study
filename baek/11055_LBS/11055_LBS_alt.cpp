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
    dp[n] = arr[n];

    for (int i = n + 1; i < N; ++i)
    {
        // 증가하는 부분수열이고
        if (arr[n] < arr[i])
        {
            // 이미 dp가 계산됬을 수 도 있고
            // 현재 dp에 저장된 값 보다 다음 증가하는 수열의 수를 더한 값이 더 크다면
            // dp 갱신
            dp[n] = max(dp[n], solve(i) + arr[n]);
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