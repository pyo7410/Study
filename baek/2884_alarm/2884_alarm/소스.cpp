#include <iostream>
using namespace std;

// 0보다 작으면 이미 음수이므로 뺄셈이 아닌 덧셈으로 해야한다!!
// alarm_m 뿐만 아니라 alarm_h도 음수값 고려해야 한다!!

int main()
{
	int h, m;
	int alarm_h, alarm_m;

	cin >> h >> m;

	alarm_m = m - 45;

	if (alarm_m < 0)
	{
		alarm_h = h - 1;

		if (alarm_h < 0)
		{
			alarm_h = 24 + alarm_h;
		}

		alarm_m = 60 + alarm_m;
	}
	else
	{
		alarm_h = h;
	}

	cout << alarm_h << " " << alarm_m << endl;
}