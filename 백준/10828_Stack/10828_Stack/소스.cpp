#include <iostream>
#include <string>
using namespace std;

/*
stack�� ������ �׿��־ �������.
Why? size�� ���� �����ָ� �Ǵϱ�! �����Ⱑ ����!
cin�� ��ȯ���� �Է¹��� ���� ��ȯ�Ѵ�!!
*/

class Stack {
private :
	int stack[10000];
	int num = 0;

public :
	void push(int x)
	{
		stack[num] = x;
		num += 1;
	}

	int empty()
	{
		if (num == 0)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	
	int pop()
	{
		if (empty())
		{
			return -1;
		}
		else
		{
			num -= 1;
			return stack[num];
		}
	}

	int size()
	{
		return num;
	}

	int top()
	{
		if (empty())
		{
			return -1;
		}
		else
		{
			return stack[num - 1];
		}
	}
};

int main()
{
	int n, x;
	string str;
	Stack s;

	cin >> n;

	while (n--)
	{
		cin >> str;

		if (str == "push")
		{
			cin >> x;
			s.push(x);
		}

		else if (str == "pop")
		{
			cout << s.pop() << "\n";
		}

		else if (str == "size")
		{
			cout << s.size() << "\n";
		}

		else if (str == "empty")
		{
			cout << s.empty() << "\n";
		}

		else if (str == "top")
		{
			cout << s.top() << "\n";
		}
	}
}