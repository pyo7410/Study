#include <iostream>
using namespace std;

int main()
{
	int num1, num2;
	int n1, n2, n3;

	cin >> num1 >> num2;

	n1 = num2 / 100;
	n2 = (num2 - (n1 * 100)) / 10;
	n3 = num2 - (n1 * 100) - (n2 * 10);

	cout << num1 * n3 << endl;
	cout << num1 * n2 << endl;
	cout << num1 * n1 << endl;
	cout << (num1 * n1 * 100) + (num1 * n2 * 10) + (num1 * n3) << endl;
}