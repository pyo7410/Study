#include <iostream>
using namespace std;

int gcd(int a, int b)
{
	int r;
	while (b != 0)
	{
		r = a % b;
		a = b;
		b = r;
	}

	return a;
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
		long long result = 0;
		int arr[101];

		cin >> n;

		for (int i = 0; i < n; ++i)
		{
			cin >> arr[i];
		}

		for (int i = 0; i < (n - 1); ++i)
		{
			for (int j = i + 1; j < n; ++j)
			{
				result += gcd(arr[i], arr[j]);
			}
		}

		cout << result << "\n";
	}
}