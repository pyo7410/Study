#include <iostream>
#include <string>
using namespace std;

/*
���� Stack�� �� �ְ� ���� ���� ������ �� ������ �����ϴ�!!
�ݺ������� �������� �Լ��� ���!
�� ������ �ִ�...... break, continue ������ �����.. �� return���� ������ �ٽ� �ݺ���Ű�°�
���Űǰ��� �̷�...
*/

string bracket(string str)
{
	int cnt = 0;

	for (char ch : str)
	{
		if (ch == '(')
		{
			cnt += 1;
		}
		else if (ch == ')')
		{
			if (cnt == 0)
			{
				return "NO\n";
			}
			else
			{
				cnt -= 1;
			}
		}
	}

	if (cnt != 0)
	{
		return "NO\n";
	}
	else
	{
		return "YES\n";
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string str;
	int n;

	cin >> n;
	while (n--)
	{
		cin >> str;
		
		cout << bracket(str);
	}
}