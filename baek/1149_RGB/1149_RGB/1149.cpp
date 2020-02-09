#include <iostream>
#include <algorithm>
using namespace std;

int d[1001][3];
int a[1001][3];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= 3; ++j)
		{
			cin >> a[i][j];
		}
	}

	for (int i = 1; i <= n; ++i)
	{
		d[i][1] = min(d[i - 1][2], d[i - 1][3]) + a[i][1];
		d[i][2] = min(d[i - 1][1], d[i - 1][3]) + a[i][2];
		d[i][3] = min(d[i - 1][1], d[i - 1][2]) + a[i][3];
	}

	cout << min({d[n][1], d[n][2], d[n][3]}) << "\n";
}
