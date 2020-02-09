#include <iostream>
using namespace std;

const long long mod = 1000000009LL;
long long d[1000001];

long long ott(int n)
{
	if (n == 0 || n == 1)
	{
		return 1;
	}
	if (n < 0)
	{
		return 0;
	}
	if (d[n] > 0)
	{
		return d[n];
	}
	d[n] = (ott(n - 1) % mod) + (ott(n - 2) % mod) + (ott(n - 3) % mod);
	return d[n];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	/*Bottom-up*/
	d[0] = 1;
	for (int i = 1; i <= 1000000; ++i)
	{
		if (i - 1 >= 0)
		{
			d[i] += d[i - 1];
		}
		if (i - 2 >= 0)
		{
			d[i] += d[i - 2];
		}
		if (i - 3 >= 0)
		{
			d[i] += d[i - 3];
		}
		d[i] %= mod;
	}

	int t, n;
	cin >> t;

	while (t--)
	{
		cin >> n;

		/*Top-down*/
		//cout << ott(n) % mod << "\n";

		cout << d[n] << "\n";
	}
}
