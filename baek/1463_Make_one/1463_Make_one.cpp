#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
int dp[1000001];

int solve(int start)
{
    if (start == 1)
    {
        return 0;
    }

    // 메모이제이션을 사용하여
    // 완전탐색을 DP로 변환
    if (dp[start] != -1)
    {
        return dp[start];
    }

    // start 부터 1까지 완전탐색을 해준다.
    dp[start] = solve(start - 1) + 1;

    if (start % 2 == 0)
    {
        dp[start] = min(dp[start], solve(start / 2) + 1);
    }
    if (start % 3 == 0)
    {
        dp[start] = min(dp[start], solve(start / 3) + 1);
    }

    return dp[start];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int n;
    cin >> n;

    memset(dp, -1, sizeof(dp));

    cout << solve(n) << "\n";

    return 0;
}
