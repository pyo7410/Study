#include <iostream>
#include <stack>
#include <string>
using namespace std;

/*
���� ���ڸ� �߰������� Pop�� ������ϴ°��� ��������!!
pop()�� �ϸ� top()�� ���� �ٲ��... �̸� top()�� ���� ������..
�ٷιٷ� ����ϸ� �ȵȴ�
Why? NO�� ��� NO�� ��µǾ���...
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