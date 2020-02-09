#include <iostream>
#include <stack>
#include <string>
using namespace std;

/*
foreach�� ������ �ݵ��
for (�ڷ��� ������ : ����)
�������� �ڷ����� �ȿ��� ����ؾ��Ѵ�!

cin�� ������ ������ ������ �����Ͽ� �Է¹����Ƿ�
getline�� ����Ͽ� ������ �����ؾ��Ѵ�!
*/

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string str;
	stack<char> s;
	int t;

	cin >> t;
	cin.ignore();

	while (t--)
	{
		getline(cin, str);
		str += "\n";

		for (char ch : str)
		{
			if (ch == ' ' || ch == '\n')
			{
				while (!s.empty())
				{
					cout << s.top();
					s.pop();
				}
				cout << ch;
			}
			else
			{
				s.push(ch);
			}
		}
	}
}