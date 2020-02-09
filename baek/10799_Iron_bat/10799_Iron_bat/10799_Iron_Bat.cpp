#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	stack<int> s;
	string str;
	int result = 0; int idx = 0;

	cin >> str;

	for (char ch : str)
	{
		if (ch == '(')
		{
			s.push(idx);
			idx += 1;
		}
		if (ch == ')')
		{
			if ((idx - s.top()) == 1)
			{
				s.pop();
				result += s.size();
			}
			else
			{
				s.pop();
				result += 1;
			}
		}
	}

	cout << result << "\n";
}