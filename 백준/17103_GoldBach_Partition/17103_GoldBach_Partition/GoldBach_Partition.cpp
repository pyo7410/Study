#include <iostream>
#include <vector>
using namespace std;

bool check[1000001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int t, n;
	int ans;
	vector<int> prime;
	for (int i = 2; i <= 1000000; ++i)
	{
		if (check[i] == false)
		{
			prime.push_back(i);
			for (int j = i * 2; j <= 1000000; j += i)
			{
				check[j] = true;
			}
		}
	}

	cin >> t;
	while (t--)
	{
		cin >> n;
		ans = 0;
		for (int i = 0; i < prime.size(); ++i)
		{
			if (n - prime[i] >= 2 && prime[i] <= n - prime[i])
			{
				if (check[n - prime[i]] == false)
				{
					ans += 1;
				}
			}
			else
			{
				break;
			}
		}
		cout << ans << "\n";
	}
}