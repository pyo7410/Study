#include <iostream>
#include <string>
using namespace std;

/*
굳이 Stack에 안 넣고 덧셈 뺄셈 만으로 더 빠르게 가능하다!!
반복문으로 쓰지말고 함수를 써라!
다 이유가 있다...... break, continue 관리가 힘들다.. 걍 return으로 돌리고 다시 반복시키는게
정신건강에 이롭...
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