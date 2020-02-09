#include <iostream>
using namespace std;

long long d[101];

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

		d[1] = 1;
		d[2] = 1;

		for (int i = 3; i <= n; ++i)
		{
			d[i] = d[i - 3] + d[i - 2];
		}

		cout << d[n] << "\n";
	}
}
