#include <iostream>
#include <string>
using namespace std;

class Deque
{
private :
	int dq[10000];
	//int idx = 0;
	int begin = 0, end = 0;
public :
	void push_front(int x)
	{
		dq[begin] = x;
		begin = begin
	}
	void push_back(int x)
	{
		dq[end++] = x;
		idx = end;
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
	int pop_front()
	{
		if (empty())
		{
			return -1;
		}
		else
		{
			return dq[begin++];
		}
	}
	int pop_back()
	{
		if (empty())
		{
			return -1;
		}
		else
		{
			return dq[--end];
		}
	}
	int size()
	{
		return end - begin;
	}
	int front()
	{
		return dq[begin];
	}
	int back()
	{
		return dq[end - 1];
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	Deque dq;
	string str;
	int n, x;

	cin >> n;
	while (n--)
	{
		cin >> str;
		
		if (str == "push_front")
		{
			cin >> x;
			dq.push_front(x);
		}
		else if (str == "push_back")
		{
			cin >> x;
			dq.push_back(x);
		}
		else if (str == "pop_front")
		{
			cout << dq.pop_front() << "\n";
		}
		else if (str == "pop_back")
		{
			cout << dq.pop_back() << "\n";
		}
		else if (str == "size")
		{
			cout << dq.size() << "\n";
		}
		else if (str == "empty")
		{
			cout << dq.empty() << "\n";
		}
		else if (str == "front")
		{
			cout << dq.front() << "\n";
		}
		else if (str == "back")
		{
			cout << dq.back() << "\n";
		}
	}
}