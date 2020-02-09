#include <iostream>
#include <string>
using namespace std;

/*
stack에 값들이 쌓여있어도 상관없다.
Why? size로 접근 시켜주면 되니깐! 덮어씌우기가 가능!
cin의 반환값은 입력받은 수를 반환한다!!
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