#include <iostream>
#include <algorithm>
using namespace std;

long long d[3][100001];
long long a[3][100001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int t, n;
    cin >> t;

    while (t--)
    {
        cin >> n;
        
        for (int i = 1; i <= n; ++i)
        {
            cin >> a[0][i];
        }
        for (int i = 1; i <= n; ++i)
        {
            cin >> a[1][i];
        }

        for (int i = 1; i <= n; ++i)
        {
            d[0][i] = max({d[0][i - 1], d[1][i - 1], d[2][i - 1]});
            d[1][i] = max(d[0][i - 1], d[2][i - 1]) + a[0][i];
            d[2][i] = max(d[0][i - 1], d[1][i - 1]) + a[1][i];
        }

        cout << max({d[0][n], d[1][n], d[2][n]}) << "\n";
    }
}
