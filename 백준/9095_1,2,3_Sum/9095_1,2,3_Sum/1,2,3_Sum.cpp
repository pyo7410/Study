#include <iostream>
using namespace std;

// top down
int d[12];
int sum(int n)
{
	if (n <= 1)
	{
		return 1;
	}
	if (n == 2)
	{
		return 2;
	}

	d[n] = sum(n - 1) + sum(n - 2) + sum(n - 3);

	return d[n];
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
		cout << sum(n) << "\n";
	}
	/* Botton up
	while (t--)
	{
		int d[12];

		cin >> n;

		d[0] = 1;
		d[1] = 1;
		d[2] = 2;
		for (int i = 3; i <= n; ++i)
		{
			d[i] = d[i - 1] + d[i - 2] + d[i - 3];
		}

		cout << d[n] << "\n";
	}
	*/
}