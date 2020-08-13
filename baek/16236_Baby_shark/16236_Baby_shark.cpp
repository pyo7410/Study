#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};

int n;
int target_i, target_j, min_dist;
int weight;

int a[21][21];
int dist[21][21];

void bfs(int i, int j)
{
    queue<pair<int, int>> q;
    q.push(make_pair(i, j));
    dist[i][j] = 0;

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for (int k = 0; k < 4; ++k)
        {
            int nx = x + dx[k];
            int ny = y + dy[k];
            
            if (nx >= 0 && nx < n && ny >= 0 && ny < n)
            {
                // �̹� �湮�ߴ��� ����� ���Ժ��� Ŭ ���
                if (dist[nx][ny] != -1 || a[nx][ny] > weight)
                {
                    continue;
                }

                // �̵������Ƿ� +1
                dist[nx][ny] = dist[x][y] + 1;

                // ����� ���Ժ��� ���� ���
                // �̹� �̵������Ƿ� ���� ���� �Ѿ�� �ȴ�.
                if (a[nx][ny] > 0 && a[nx][ny] < weight)
                {
                    if (min_dist > dist[nx][ny]) // �Ÿ��� ���� ª�� ��ġ��
                    {
                        target_i = nx;
                        target_j = ny;
                        min_dist = dist[nx][ny];
                    }
                    else if (min_dist == dist[nx][ny]) // �Ÿ��� ���� ���
                    {
                        if (nx < target_i) // ���� �� �� �ε�ȣ Ȯ��!!!
                        {
                            target_i = nx;
                            target_j = ny;
                        }
                        else if (nx == target_i && ny < target_j) // ������ �������� ��� ���� ����
                        {
                            target_j = ny;
                        }        
                    }
                }
                // �̵��� ��ġ�� ť�� push
                q.push(make_pair(nx, ny));
            }
        }
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
    
    // ū ����� ĭ x, ���� ����� ĭ -> +1, ���� ������ ���� ���ϰ� �� ����
    // �Ʊ�� ��� ��ȸ�ϸ� ������� ȣ�� ��, ��

    cin >> n;

    int start_i, start_j;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> a[i][j];
            if (a[i][j] == 9)
            {
                start_i = i;
                start_j = j;

                // ���� ��ġ 0���� �ʱ�ȭ
                a[start_i][start_j] = 0;
            }
        }    
    }

    int ans = 0;

    // �Ʊ���� �ڽ��� ũ��� ���� ���� ����⸦ ���� ������
    // ũ�Ⱑ 1 ����
    int eat_fish = 0;
    
    // ��� ���� �ʱ�ȭ
    weight = 2;

    // �̵��� ��� ��ġ�� �������� �Ź� ����⸦ ã�� �̵��Ѵ�.
    while (1)
    {
        // n�� �ִ� 20�̹Ƿ� �� �ð��� 20*20 ��, 400�� ���� �� ����.
        target_i = 21;
        target_j = 21;
        min_dist = 401;

        // dist�� �ٽ� -1�� �ʱ�ȭ
        memset(dist, -1, sizeof(dist));

        // ���� ����� ���� �� �ִ� ����⸦ ã�´�.
        bfs(start_i, start_j);

        if (target_i < 21 && target_j < 21)
        {
            ans += dist[target_i][target_j];
            eat_fish += 1;

            if (eat_fish == weight)
            {
                weight += 1;
                eat_fish = 0;
            }

            // ���� ��ġ�� 0���� ������ �Ѵ�.
            a[target_i][target_j] = 0;

            // �� ������ġ�� �̵������Ƿ�
            start_i = target_i;
            start_j = target_j;
        }
        else // �������� �����Ƿ� ������� ȣ��
        {
            break;
        }
    }

    cout << ans << "\n";

    return 0;
}
