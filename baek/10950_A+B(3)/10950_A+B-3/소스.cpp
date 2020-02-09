#include <iostream>
using namespace std;

int main()
{
	int count;
	int i, a, b;

	cin >> count;

	for (i = 0; i < count; ++i)
	{
		cin >> a >> b;
		cout << a + b << endl;
	}
}