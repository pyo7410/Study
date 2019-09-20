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

int lcm(int a, int b, int g)
{
	return g * (a / g) * (b / g);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int a, b, g;
	cin >> a >> b;

	g = gcd(a, b);
	cout << g << "\n" << lcm(a, b, g) << "\n";
}