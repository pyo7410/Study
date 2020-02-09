#include <iostream>
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

	int t, a, b, g;

	cin >> t;

	while (t--)
	{
		cin >> a >> b;
		
		g = gcd(a, b);

		cout << g * (a / g) * (b / g) << "\n";
	}
}