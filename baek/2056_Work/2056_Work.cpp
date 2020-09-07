#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<int>> work;
vector<int> result;
vector<int> in;
vector<int> work_time;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;

	work.resize(n + 1);
	result.resize(n + 1);
	in.resize(n + 1);
	work_time.resize(n + 1);

	// �۾��� 1���� ����
	for (int i = 1; i <= n; ++i)
	{
		int time;
		cin >> time;
		work_time[i] = time;

		int cnt;
		cin >> cnt;

		while (cnt--)
		{
			int a;
			cin >> a;

			// ���� �۾�(i)�� �ش��ϴ�
			// ���� �۾�(a)���� �־��ش�.
			work[a].push_back(i);

			// ���� ������ +1 ���ش�.
			in[i] += 1;
		}
	}

	queue<int> q;

	for (int i = 1; i <= n; ++i)
	{
		if (!in[i])
		{
			q.push(i);
			result[i] = work_time[i];
		}
	}

	for (int i = 1; i <= n; ++i)
	{
		if (q.empty())
		{
			break;
		}
		
		int x = q.front();
		q.pop();

		for (int j = 0; j < work[x].size(); ++j)
		{
			int y = work[x][j];

			if (result[y] < result[x] + work_time[y])
			{
				result[y] = result[x] + work_time[y];
			}

			if (--in[y] == 0)
			{
				q.push(y);
			}
		}
	}

	cout << *max_element(result.begin(), result.end()) << "\n";

	return 0;
}
