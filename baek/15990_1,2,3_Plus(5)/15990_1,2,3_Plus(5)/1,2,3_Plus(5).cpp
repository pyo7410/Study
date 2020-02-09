#include <iostream>
using namespace std;

long long d[100001][4];
const long long mod = 1000000009LL;
const int limit = 100000;

long long plus5(int n, int i)
{
	if (n == i)
	{
		return 1;
	}
	if (d[n][i] > 0)
	{
		return d[n][i];
	}
	
	if (i == 1 && (n - 1 > 0))
	{
		d[n][i] = plus5(n - 1, 2) + plus5(n - 1, 3);
	}
	else if (i == 2 && (n - 2 > 0))
	{
		d[n][i] = plus5(n - 2, 1) + plus5(n - 2, 3);
	}
	else if (i == 3 && (n - 3 > 0))
	{
		d[n][i] = plus5(n - 3, 1) + plus5(n - 3, 2);
	}

	d[n][i] %= mod;

	return d[n][i];
}

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

		// Bottom-up
		/*
		for (int i = 1; i <= n; ++i)
		{
			if (i - 1 >= 0)
			{
				d[i][1] = d[i - 1][2] + d[i - 1][3];
				if (i == 1)
				{
					d[i][1] = 1;
				}
			}
			if (i - 2 >= 0)
			{
				d[i][2] = d[i - 2][1] + d[i - 2][3];
				if (i == 2)
				{
					d[i][2] = 1;
				}
			}
			if (i - 3 >= 0)
			{
				d[i][3] = d[i - 3][1] + d[i - 3][2];
				if (i == 3)
				{
					d[i][3] = 1;
				}
			}

			d[i][1] %= mod;
			d[i][2] %= mod;
			d[i][3] %= mod;
		}
		cout << (d[n][1] + d[n][2] + d[n][3]) % mod << "\n";
		*/

		cout << (plus5(n, 1) + plus5(n, 2) + plus5(n, 3)) % mod << "\n";
	}	
}