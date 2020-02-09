#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int v[1001];
int a[1001];

void go(int p)
{
	if (p == 0)
	{
		return;
	}

	go(v[p]);
	cout << a[p] << " ";
}

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
			if (a[i] > a[j] && d[i] < d[j] + 1)
			{
				d[i] = d[j] + 1;
				v[i] = j;
			}
		}
	}

	cout << *max_element(d.begin(), d.end()) << "\n";
	go(max_element(d.begin(), d.end()) - d.begin());
}
