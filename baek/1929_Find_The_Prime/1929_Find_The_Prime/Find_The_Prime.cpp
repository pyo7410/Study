#include <iostream>
using namespace std;

bool check[1000001];
int prime[1000000];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int m, n;	
	int pn = 0;	

	cin >> m >> n;

	for (int j = 2; j <= n; ++j)
	{
		if (check[j] == false)
		{
			if (j >= m)
			{
				prime[pn++] = j;
			}
			for (int i = (j * 2); i <= n; i += j)
			{
				check[i] = true;
			}
		}
	}

	for (int i = 0; i < pn; ++i)
	{
		cout << prime[i] << "\n";
	}
}