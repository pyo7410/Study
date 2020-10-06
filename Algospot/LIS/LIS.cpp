#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
int arr[501];
int dp[501];

int solve(int start)
{
    // 이미 계산된 값이라면
    if (dp[start] != -1)
    {
        return dp[start];
    }

    // 무조건 시작점은 존재하므로
    dp[start] = 1;

    for (int i = start + 1; i < n; ++i)
    {
        if (arr[start] < arr[i])
        {
            // 횟 수를 구하는 문제이므로 solve(i)의 결과값에 현재 위치를 더하기 위해 + 1을 해주면 된다.
            dp[start] = max(dp[start], solve(i) + 1);
        }
    }

    return dp[start];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int c;
    cin >> c;

    while (c--)
    {
        memset(dp, -1, sizeof(dp));
        memset(arr, 0, sizeof(arr));
        cin >> n;

        for (int i = 0; i < n; ++i)
        {
            cin >> arr[i];
        }

        // 각 인덱스마다 더 긴 LIS가 존재할 수 있으므로
        int maxLen = 0;
        for (int i = 0; i < n; ++i)
        {
            maxLen = max(maxLen, solve(i));
        }

        cout << maxLen << "\n";
    }

    return 0;
}
