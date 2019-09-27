#include <iostream>
using namespace std;

long long d[101][10];
long long mod = 1000000000LL;

// top-down
int staircase(int n, int i)
{
	if (n == 1)
	{
		if (i == 0)
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}

	if (d[n][i] > 0)
	{
		return d[n][i];
	}

	//d[n][i] = staircase(n - 1, i - 1) + staircase(n - 1, i + 1);

	if (i - 1 >= 0)
	{
		d[n][i] += staircase(n - 1, i - 1);
	}
	if (i + 1 <= 9)
	{
		d[n][i] += staircase(n - 1, i + 1);
	}

	d[n][i] %= mod;

	return d[n][i];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	long long result = 0;

	cin >> n;

	// Bottom-Up
	/*
	for (int i = 1; i <= 9; ++i)
	{
		d[1][i] = 1;
	}

	for (int i = 2; i <= n; ++i)
	{
		for (int j = 0; j <= 9; ++j)
		{
			if (j - 1 >= 0)
			{
				d[i][j] += d[i - 1][j - 1];
			}
			if (j + 1 <= 9)
			{
				d[i][j] += d[i - 1][j + 1];
			}
			d[i][j] %= mod;
		}
	}

	for (int i = 0; i <= 9; ++i)
	{
		result += d[n][i];
	}

	cout << result % mod << "\n";
	*/

	// top-down
	for (int i = 0; i <= 9; ++i)
	{
		result += staircase(n, i);
	}

	cout << result % mod << "\n";
}