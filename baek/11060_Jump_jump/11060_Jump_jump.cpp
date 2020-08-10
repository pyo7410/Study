#include <iostream>
#include <cstring>
using namespace std;

int a[1001];
int dp[1001];
int n;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }

    memset(dp, -1, sizeof(dp));

    dp[1] = 0;
    for (int i = 1; i <= n; ++i)
    {
        // 한번도 방문안했으므로 갈 수 가 없는 점이 된다!!
        if (dp[i] == -1)
        {
            break;
        }
        for (int j = 1; j <= a[i]; ++j)
        {

            if (dp[i + j] == -1)
            {
                dp[i + j] = dp[i] + 1;
            }
        }
    }

    cout << dp[n] << "\n";
    
    return 0;
}
