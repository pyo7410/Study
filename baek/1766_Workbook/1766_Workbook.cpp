#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int in[32001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    // 1 ~ n ���� �̹Ƿ� n + 1
    vector<vector<int>> v(n + 1);

    for (int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;

        v[a].push_back(b);

        // ������ ������ ��� +1
        in[b] += 1;
    }

    priority_queue<int> q;
    for (int i = 1; i <= n; ++i)
    {
        if (!in[i])
        {
            // -�� �ϰ� �켱���� ť�� �־��ָ� ���� ������ �켱������ �� Ŀ���� �Ǿ�
            // �������� �䱸�ϴ� ���� ������ ���� Ǭ�ٰ� ������ ����.
            q.push(-i);
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        // �׻� ������ ��� Ǯ �� �ִ� ��츸 �־����Ƿ� ť�� ��������� �Ⱥ��� �ȴ�.
        int x = -q.top();
        cout << x << " ";
        q.pop();

        for (int j = 0; j < v[x].size(); ++j)
        {
            int y = v[x][j];

            if (--in[y] == 0)
            {
                q.push(-y);
            }
        }
    }
    
    return 0;
}
