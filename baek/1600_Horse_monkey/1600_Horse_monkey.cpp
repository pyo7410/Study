#include <iostream>
#include <queue>
using namespace std;

int h_dx[] = {2, 2, 1, 1, -1, -1, -2, -2};
int h_dy[] = {1, -1, 2, -2, 2, -2, 1, -1};

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int k, w, h;
int arr[201][201];

// queue�� ���� �ɷ� ������ ���� ������ �ɷ��� ����
// ���ŵ��� �ʰ� �ٸ� ��ο��� ����� ���� �״�� ���ǹǷ�
// ���� �ȳ��´�.
// �׷��Ƿ� visited�� �ϳ��� ������ �� �߰��� ���� �ɷ¿� ���� �湮�� üũ�Ѵ�
bool visited[201][201][31];

void bfs()
{
    // a, b, ������ Ƚ��, ��ó�� ������ Ƚ��
    queue<pair<pair<int, int>, pair<int, int>>> q;
    q.push({{1, 1}, {0, 0}});

    // a, b, ���� �ɷ��� ��
    visited[1][1][0] = true;

    // 1, 1���� �����ϵ��� �����Ƿ� queue�� ó�� �������� visited�� ó�� �����Ҷ�
    // 0, 0�� �ƴ� 1, 1�� �ϴ°��� ����

    while (!q.empty())
    {
        int x = q.front().first.first;
        int y = q.front().first.second;

        int cnt = q.front().second.first;
        int h_cnt = q.front().second.second;
        
        q.pop();

        // ���� �������� ���
        if (x == h && y == w)
        {
            cout << cnt << "\n";
            return;
        }

        if (h_cnt < k)
        {
            for (int i = 0; i < 8; ++i)
            {
                int nx = x + h_dx[i];
                int ny = y + h_dy[i];

                if (nx > 0 && nx <= h && ny > 0 && ny <= w)
                {
                    // nx, ny�� ���������� ��ο� ���� ���� �ɷ��� ���� ���� �޶�����!
                    // �׷��Ƿ� visited�� �ϳ��� ������ �� �߰��� ���� �ɷ¿� ���� �湮�� üũ�Ѵ�
                    if (!visited[nx][ny][h_cnt + 1] && arr[nx][ny] == 0)
                    {
                        visited[nx][ny][h_cnt + 1] = true;

                        // arr[nx][ny] = arr[x][y] + 1�� ���ϴ������� arr[x][y]�� 0�̸� arr[nx][ny]�� 1�� �ǰ�
                        // 1�� ��ֹ��̱� ������ ��ġ�� �ǹǷ� ���� �ʴ´�
                        q.push({{nx, ny}, {cnt + 1, h_cnt + 1}});
                    }
                }
            }
        }

        for (int i = 0; i < 4; ++i)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx > 0 && nx <= h && ny > 0 && ny <= w)
            {
                // nx, ny�� ���������� ��ο� ���� ���� �ɷ��� ���� ���� �޶�����!
                // �׷��Ƿ� visited�� �ϳ��� ������ �� �߰��� ���� �ɷ¿� ���� �湮�� üũ�Ѵ�

                // �Ϲ� �̵��ÿ��� �ɷ��� ���� �����Ƿ� h_cnt + 1�� ���� �ʰ� �״�� ���Ѵ�!
                if (!visited[nx][ny][h_cnt] && arr[nx][ny] == 0)
                {
                    visited[nx][ny][h_cnt] = true;

                    // arr[nx][ny] = arr[x][y] + 1�� ���ϴ������� arr[x][y]�� 0�̸� arr[nx][ny]�� 1�� �ǰ�
                    // 1�� ��ֹ��̱� ������ ��ġ�� �ǹǷ� ���� �ʴ´�

                    // �Ϲ� �̵��ÿ��� �ɷ��� ���� �����Ƿ� h_cnt + 1�� ���� �ʰ� �״�� ���Ѵ�!
                    q.push({{nx, ny}, {cnt + 1, h_cnt}});
                }
            }
        }
    }

    // while������ �������Դٸ�
    // ������ ���� ���Ѱ�!
    cout << -1 << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> k;
    cin >> w >> h;

    // h�� ���� w�� �ʺ��̹Ƿ�
    // i�� h, j�� w ���� �ݺ�
    for (int i = 1; i <= h; ++i)
    {
        for (int j = 1; j <= w; ++j)
        {
            cin >> arr[i][j];
        }
    }

    bfs();    

    return 0;
}
