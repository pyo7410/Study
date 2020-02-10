#include <iostream>
using namespace std;

#define mod 10007

int d[1001][10];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int n;
    long long ans = 0;
    cin >> n;

    for (int i = 0; i <= 9; ++i)
    {
        d[1][i] = 1;
    }

    for (int i = 2; i <= n; ++i)
    {
        for (int j = 0; j <= 9; ++j)
        {
            for (int k = 0; k <= j; ++k)
            {
                d[i][j] += d[i - 1][k];
                d[i][j] %= mod;
            }
        }
    }

    for (int i = 0; i <= 9; ++i)
    {
        ans += d[n][i];
    }

    cout << ans % mod << "\n";
}
