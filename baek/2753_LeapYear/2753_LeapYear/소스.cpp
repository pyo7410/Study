#include <iostream>
using namespace std;

// 최소 범위 즉, 100이하의 수도 생각해야한다!
// 방법1. 100보다 큰 수 작은 수 따로 하기

int main()
{
	int year;

	cin >> year;

	if ((year % 4) > 0)
	{
		cout << "0" << endl;
	}

	else if ((year % 4) == 0)
	{
		if ((year % 100) != 0)
		{
			cout << "1" << endl;
		}
		else if ((year % 400) == 0)
		{
			cout << "1" << endl;
		}
		else
		{
			cout << "0" << endl;
		}
	}
	else
	{
		cout << "0" << endl;
	}
}