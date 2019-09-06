#include <iostream>
using namespace std;

int main()
{
	int count, i, a, b;

	cin >> count;

	for (i = 1; i <= count; ++i)
	{
		cin >> a >> b;

		cout << "Case #" << i << ": " << a + b << "\n";
	}
}