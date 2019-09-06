#include <iostream>
using namespace std;

int sum(int n)
{
	if (n > 1)
	{
		return sum(n - 1) + n;
	}
	else
	{
		return n;
	}
}

int main()
{
	int num, result;

	cin >> num;

	cout << sum(num) << endl;
}