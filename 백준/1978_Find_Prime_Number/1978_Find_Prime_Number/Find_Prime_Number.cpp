#include <iostream>
using namespace std;

bool prime(int a)
{
	if (a < 2)
	{
		return false;
	}

	for (int i = 2; (i * i) <= a; ++i)
	{
		if (a % i == 0)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, a, cnt = 0;
	cin >> n;

	while (n--)
	{
		cin >> a;
		if (prime(a))
		{
			cnt++;
		}		
	}

	cout << cnt << "\n";
}