#include <iostream>
#include <string>
using namespace std;

class Queue
{
private :
	int q[10000];
	int begin = 0, end = 0;
public :
	void push(int x)
	{
		q[end++] = x;
	}
	int empty()
	{
		if (begin == end)
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
			return q[begin++];
		}
	}
	int size()
	{
		return end - begin;
	}
	int front()
	{
		if (empty())
		{
			return -1;
		}
		else
		{
			return q[begin];
		}
	}
	int back()
	{
		if (empty())
		{
			return -1;
		}
		else
		{
			return q[end - 1];
		}
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	Queue q;
	string str;
	int n, x;

	cin >> n;
	while (n--)
	{
		cin >> str;

		if (str == "push")
		{
			cin >> x;
			q.push(x);
		}
		else if (str == "pop")
		{
			cout << q.pop() << "\n";
		}
		else if (str == "size")
		{
			cout << q.size() << "\n";
		}
		else if (str == "empty")
		{
			cout << q.empty() << "\n";
		}
		else if (str == "front")
		{
			cout << q.front() << "\n";
		}
		else if (str == "back")
		{
			cout << q.back() << "\n";
		}
	}
}