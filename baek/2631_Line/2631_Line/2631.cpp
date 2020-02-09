#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int a[201];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;

	vector<int> d(n + 1);

	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}

	for (int i = 1; i <= n; ++i)
	{
		d[i] = 1;
		for (int j = 1; j <= i; ++j)
		{
			if (a[j] < a[i] && d[i] < d[j] + 1)
			{
				d[i] = d[j] + 1;
			}
		}
	}

	cout << n - *max_element(d.begin(), d.end()) << "\n";
}
