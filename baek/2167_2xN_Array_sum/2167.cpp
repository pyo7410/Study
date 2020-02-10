#include <iostream>
#include <vector>
using namespace std;

int d[301][301];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m, k;
	int input_i, input_j, x, y;
	int ans;
	cin >> n >> m; 

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			cin >> d[i][j];
		}
	}

	cin >> k;
	while (k--)
	{
		ans = 0;
		cin >> input_i >> input_j >> x >> y;

		for (int i = input_i; i <= x; ++i)
		{
			for (int j = input_j; j <= y; ++j)
			{
				ans += d[i][j];
			}
		}
		cout << ans << "\n";
	}
}