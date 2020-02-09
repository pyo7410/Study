#include <iostream>
using namespace std;

int d[10001];
int tiling(int n)
{
	if (n < 0)
	{
		return 0;
	}

	if (n == 0)
	{
		return 1;
	}

	if (d[n] > 0)
	{
		return d[n];
	}

	d[n] = tiling(n - 1) % 10007 + tiling(n - 2) % 10007;

	return d[n];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, result;

	cin >> n;

	cout << tiling(n) % 10007 << "\n";
}