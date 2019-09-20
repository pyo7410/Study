#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	long long n, m;
	long long ans_2 = 0, ans_5 = 0;

	cin >> n >> m;

	for (long long i = 2; i <= n; i *= 2)
	{
		ans_2 += n / i;
	}
	for (long long i = 2; i <= n - m; i *= 2)
	{
		ans_2 -= (n - m) / i;
	}
	for (long long i = 2; i <= m; i *= 2)
	{
		ans_2 -= m / i;
	}

	for (long long i = 5; i <= n; i *= 5)
	{
		ans_5 += n / i;
	}
	for (long long i = 5; i <= n - m; i *= 5)
	{
		ans_5 -= (n - m) / i;
	}
	for (long long i = 5; i <= m; i *= 5)
	{
		ans_5 -= m / i;
	}

	cout << min(ans_2, ans_5) << "\n";
}