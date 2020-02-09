#include <iostream>
#include <algorithm>
using namespace std;

long long d[501][501];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	long long ans;
	cin >> n;

	for (int i = 1; i <= n; ++i)
	{ 
		for (int j = 1; j <= i; ++j)
		{
			cin >> d[i][j];
		}
	}

	for (int i = 2; i <= n; ++i)
	{
		for (int j = 1; j <= i; ++j)
		{
			d[i][j] += max(d[i - 1][j - 1], d[i - 1][j]);
		}
	}

	ans = d[n][1];
	for (int i = 2; i <= n; ++i)
	{
		if (ans < d[n][i])
		{
			ans = d[n][i];
		}
	}

	cout << ans << "\n";
}
