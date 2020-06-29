#include <iostream>
#include <queue>
using namespace std;

// �������� 1��ĭ ���Ͷ� ������ 1��ĭ���� ����
// �� 0�����ʹ� �ȵǴ����� �𸣰ڴ�..

int dist[101];     // �Ÿ�
int next_col[101]; // ���� ĭ

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= 100; ++i)
    {
        dist[i] = -1;     // �Ÿ� �ʱ�ȭ
        next_col[i] = i;  // ���� ĭ �ʱ�ȭ, ��ٸ��� ���� �����ϰ�� ����ĭ���� �̵� X
    }

    while (n--) // ��ٸ� ���� �Է�
    {
        int x, y;
        cin >> x >> y;
        next_col[x] = y;
    }

    while (m--) // �� ���� �Է�
    {
        int x, y;
        cin >> x >> y;
        next_col[x] = y;
    }

    dist[1] = 0;

    queue<int> q;
    q.push(1);

    while (!q.empty()) // bfs
    {
        int x = q.front();
        q.pop();

        for (int i = 1; i <= 6; ++i)
        {
            int y = x + i; // �ֻ��� ĭ ��ŭ �̵�

            if (y > 100) // 100���� Ŭ ��츦 ����
            {
                continue;
            }

            y = next_col[y];
            if (dist[y] == -1) // �ѹ��� �湮���� ���̶��
            {
                dist[y] = dist[x] + 1; // ���� ������ 1�� �̵������Ƿ�
                q.push(y);             // ���� ĭ�� queue�� push
            }
        }
    }

    cout << dist[100] << "\n";
    
    return 0;
}
