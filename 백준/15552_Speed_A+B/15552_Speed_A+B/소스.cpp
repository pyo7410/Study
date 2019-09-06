#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int num, i, a, b;

	cin >> num;

	for (i = 0; i < num; ++i)
	{
		cin >> a >> b;
		cout << a + b << "\n";
	}
}