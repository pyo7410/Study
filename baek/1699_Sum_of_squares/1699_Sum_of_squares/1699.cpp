#include <iostream>
#include <vector>
using namespace std;

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
		d[i] = i;
		for (int j = 1; j * j <= i; ++j)
		{
			if (d[i] > d[i - j * j] + 1)
			{
				d[i] = d[i - j * j] + 1;
			}
		}
	}

	cout << d[n] << "\n";
}
