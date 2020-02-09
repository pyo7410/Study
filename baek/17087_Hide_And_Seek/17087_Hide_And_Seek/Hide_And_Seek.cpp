#include <iostream>
#include <vector>
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

	int n, s, a, ans, diff;
	cin >> n >> s;

	vector<int> vec(n);

	for (int i = 0; i < n; ++i)
	{
		cin >> a;
		diff = a - s;
		if (diff < 0)
		{
			diff = -diff;
		}
		vec[i] = diff;
	}

	ans = vec[0];
	
	for (int i = 1; i < n; ++i)
	{
		ans = gcd(ans, vec[i]);
	}

	cout << ans << "\n";
}