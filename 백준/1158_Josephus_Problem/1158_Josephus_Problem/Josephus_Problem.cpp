#include <iostream>
#include <queue>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	queue<int> q;
	int n, k, i, j;

	cin >> n >> k;
	for (i = 1; i <= n; ++i)
	{
		q.push(i);
	}

	cout << "<";

	for (i = 0; i < n - 1; ++i)
	{
		for (j = 0; j < k - 1; ++j)
		{
			q.push(q.front());
			q.pop();
		}
		cout << q.front() << ", ";
		q.pop();
	}
	cout << q.front() << ">\n";
}