#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> prime;
//int pn;
bool check[10001];
int sum;

void find_prime(int m, int n)
{
	for (int i = 2; i <= n; ++i)
	{
		if (check[i] == false)
		{
			if (i >= m && i <= n)
			{
				prime.push_back(i);
				sum += i;
			}
			for (int j = i * 2; j <= n; j += i)
			{
				check[j] = true;
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int m, n, max = 0;
	bool p_check = false;

	cin >> m >> n;

	find_prime(m, n);

	if (prime.size() != 0)
	{
		cout << sum << "\n";
		cout << *min_element(prime.begin(), prime.end()) << "\n";
	}
	else
	{
		cout << -1 << "\n";
	}
}