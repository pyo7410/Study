#include <iostream>
using namespace std;

// 0���� ������ �̹� �����̹Ƿ� ������ �ƴ� �������� �ؾ��Ѵ�!!
// alarm_m �Ӹ� �ƴ϶� alarm_h�� ������ ����ؾ� �Ѵ�!!

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