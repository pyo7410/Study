#include <iostream>
using namespace std;
#define MAX 1000000

bool check[MAX + 1];
int prime[MAX];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	int pn = 0;

	for (int i = 2; i <= MAX; ++i)
	{
		if (check[i] == false)
		{
			prime[pn++] = i;
			for (int j = i * 2; j <= MAX; j += i)
			{
				check[j] = true;
			}
		}
	}

	while (true)
	{
		cin >> n;
		
		if (n == 0)
		{
			break;
		}

		for (int i = 1; i < pn; ++i)
		{
			if (check[n - prime[i]] == false)
			{
				cout << n << " = " << prime[i] << " + " << n - prime[i] << "\n";
				break;
			}
		}
	}
}