#include <iostream>
using namespace std;

long long d[91];

long long find(int n)
{
	if (n < 3)
	{
		d[n] = 1;
		return 1;
	}
	if (d[n] > 0)
	{
		return d[n];
	}

	d[n] = find(n - 1) + find(n - 2);

	return d[n];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;

	// Bottom up
	/*
	d[1] = 1;
	d[2] = 1;

	for (int i = 3; i <= n; ++i)
	{
		d[i] = d[i - 1] + d[i - 2];
	}

	cout << d[n] << "\n";
	*/

	cout << find(n) << "\n";
}