#include <iostream>
#include <algorithm>
using namespace std;

int d[301];
int a[301];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;

	for (int i = 1; i <= n; ++i)
	{
		cin >> d[i];
	}

	a[1] = d[1];
	a[2] = max(d[2], d[1] + d[2]);
	for (int i = 3; i <= n; ++i)
	{
		a[i] = max({ a[i - 2] + d[i], a[i - 3] + d[i - 1] + d[i] });
	}

	cout << a[n] << "\n";
}
