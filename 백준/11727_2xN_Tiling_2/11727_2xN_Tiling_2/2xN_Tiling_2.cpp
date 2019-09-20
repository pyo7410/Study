#include <iostream>
using namespace std;

int d[1001];
int tiling2(int n)
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

	d[n] = tiling2(n - 1) % 10007 + tiling2(n - 2) % 10007 + tiling2(n - 2) % 10007;

	return d[n];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;

	cout << tiling2(n) % 10007 << "\n";
}