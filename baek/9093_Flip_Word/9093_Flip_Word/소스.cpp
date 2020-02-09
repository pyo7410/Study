#include <iostream>
#include <stack>
#include <string>
using namespace std;

/*
foreach를 쓸려면 반드시
for (자료형 변수명 : 범위)
형식으로 자료형을 안에다 명시해야한다!

cin은 공백이 나오면 공백을 기준하여 입력받으므로
getline을 사용하여 공백을 포함해야한다!
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