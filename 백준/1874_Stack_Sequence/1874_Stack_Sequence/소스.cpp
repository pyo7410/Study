#include <iostream>
#include <stack>
#include <string>
using namespace std;

/*
같은 숫자를 발견했을때 Pop을 해줘야하는것을 잊지말자!!
pop()을 하면 top()의 값은 바뀐다... 미리 top()의 값을 빼놓자..
바로바로 출력하면 안된다
Why? NO일 경우 NO만 출력되야해...
*/

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, num, top;
	int i = 0;
	bool found;
	stack<int> s;
	string result;

	cin >> n;
	while (n--)
	{
		cin >> num;

		if (num > i)
		{
			for (i; i < num; ++i)
			{
				s.push(i + 1);
				result += "+\n";
			}
			s.pop();
			result += "-\n";
		}
		else 
		{
			found = false;			
			if (!s.empty())
			{
				top = s.top();
				s.pop();
				result += "-\n";

				if (num == top)
				{					
					found = true;
				}
			}

			if (!found)
			{
				cout << "NO\n";
				return 0;
			}
		}
	}

	cout << result;
}