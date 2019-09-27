#include <iostream>
#include <algorithm>
using namespace std;

int d[1001];
int a[10001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, p;

	cin >> n;	
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}

	d[1] = 1;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= i; ++j)
		{
			d[i] = max(d[i], d[i - j] + a[j]);
		}
	}

	cout << d[n] << "\n";
}