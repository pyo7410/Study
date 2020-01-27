#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;

	vector<int> d(n + 1);
	vector<int> a(n + 1);

	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}

	for (int i = 1; i <= n; ++i)
	{
		d[i] = a[i];
		if (i == 1) continue;
		if (d[i - 1] + a[i] > d[i])
		{
			d[i] = d[i - 1] + a[i];
		}
	}

	int ans = d[1];
	for (int i = 2; i <= n; i++) {
		if (ans < d[i]) {
			ans = d[i];
		}
	}
	cout << ans << '\n';
	return 0;
}
