#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int freq[1000001];
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
		freq[vec[i]] += 1;
	}

	s.push(0);
	for (i = 1; i < n; ++i)
	{
		if (s.empty())
		{
			s.push(i);
		}

		while (!s.empty() && freq[vec[s.top()]] < freq[vec[i]])
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