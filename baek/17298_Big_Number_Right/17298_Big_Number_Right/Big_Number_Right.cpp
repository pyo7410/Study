#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, i;
	cin >> n;

	vector<int> vec(n), answer(n);
	stack<int> s;
	
	for (i = 0; i < n; ++i)
	{
		cin >> vec[i];
	}

	s.push(0);
	for (i = 1; i < n; ++i)
	{
		if (s.empty())
		{
			s.push(i);
		}

		while (!s.empty() && vec[s.top()] < vec[i])
		{
			answer[s.top()] = vec[i];
			s.pop();
		}
		s.push(i);
	}

	while (!s.empty())
	{
		answer[s.top()] = -1;
		s.pop();
	}
	
	for (i = 0; i < n; ++i)
	{
		cout << answer[i] << " ";
	}
	cout << "\n";
}