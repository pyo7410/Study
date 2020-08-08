#include <iostream>
using namespace std;

int dp[100000];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int n;
    cin >> n;

    if (n < 2)
    {
        cout << -1 << "\n";
        return 0;
    }

    dp[2] = 1;
    dp[3] = -1;
    for (int i = 4; i <= n; ++i)
    {
        if (i % 5 == 0)
        {
            dp[i] = i / 5;
        }
        else 
        {
            dp[i] = dp[i - 2] + dp[2];
        }    
    }

    cout << dp[n] << "\n";
    
    return 0;
}
