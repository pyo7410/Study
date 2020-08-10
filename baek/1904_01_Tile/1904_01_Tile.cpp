#include <iostream>
using namespace std;

int dp[1000001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int n;
    cin >> n;

    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; ++i)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
        dp[i] %= 15746;
    }

    cout << dp[n] << "\n";
    
    return 0;
}
