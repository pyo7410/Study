#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string str;
	char cmd;
	int num, length;
	stack<char> l_s, r_s;

	cin >> str;
	length = str.size();

	for (char ch : str)
	{
		l_s.push(ch);
	}

	cin >> num;
	while (num--)
	{
		cin >> cmd;

		if (cmd == 'P')
		{
			cin >> cmd;
			l_s.push(cmd);
		}
		else if (cmd == 'B')
		{
			if (!l_s.empty())
			{
				l_s.pop();
			}
		}
		else if (cmd == 'D')
		{
			if (!r_s.empty())
			{
				l_s.push(r_s.top());
				r_s.pop();
			}
		}
		else if (cmd == 'L')
		{
			if (!l_s.empty())
			{
				r_s.push(l_s.top());
				l_s.pop();
			}
		}
	}

	while (!l_s.empty())
	{
		r_s.push(l_s.top());
		l_s.pop();
	}

	while (!r_s.empty())
	{
		cout << r_s.top();
		r_s.pop();
	}

	cout << "\n";
}