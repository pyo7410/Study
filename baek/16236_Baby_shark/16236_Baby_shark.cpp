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
                // 이미 방문했던가 상어의 무게보다 클 경우
                if (dist[nx][ny] != -1 || a[nx][ny] > weight)
                {
                    continue;
                }

                // 이동했으므로 +1
                dist[nx][ny] = dist[x][y] + 1;

                // 상어의 무게보다 적을 경우
                // 이미 이동했으므로 같은 경우는 넘어가게 된다.
                if (a[nx][ny] > 0 && a[nx][ny] < weight)
                {
                    if (min_dist > dist[nx][ny]) // 거리가 가장 짧은 위치로
                    {
                        target_i = nx;
                        target_j = ny;
                        min_dist = dist[nx][ny];
                    }
                    else if (min_dist == dist[nx][ny]) // 거리가 같은 경우
                    {
                        if (nx < target_i) // 가장 위 꼭 부등호 확인!!!
                        {
                            target_i = nx;
                            target_j = ny;
                        }
                        else if (nx == target_i && ny < target_j) // 위에서 여러개일 경우 가장 왼쪽
                        {
                            target_j = ny;
                        }        
                    }
                }
                // 이동한 위치를 큐에 push
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
    
    // 큰 물고기 칸 x, 작은 물고기 칸 -> +1, 같은 물고기는 먹지 못하고 갈 수만
    // 아기상어가 모두 순회하면 엄마상어 호출 즉, 끝

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

                // 시작 위치 0으로 초기화
                a[start_i][start_j] = 0;
            }
        }    
    }

    int ans = 0;

    // 아기상어는 자신의 크기와 같은 수의 물고기를 먹을 때마다
    // 크기가 1 증가
    int eat_fish = 0;
    
    // 상어 무게 초기화
    weight = 2;

    // 이동한 상어 위치를 기준으로 매번 물고기를 찾고 이동한다.
    while (1)
    {
        // n은 최대 20이므로 총 시간은 20*20 즉, 400을 넘을 수 없다.
        target_i = 21;
        target_j = 21;
        min_dist = 401;

        // dist를 다시 -1로 초기화
        memset(dist, -1, sizeof(dist));

        // 가장 가까운 먹을 수 있는 물고기를 찾는다.
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

            // 먹은 위치는 0으로 없에야 한다.
            a[target_i][target_j] = 0;

            // 상어가 먹이위치로 이동했으므로
            start_i = target_i;
            start_j = target_j;
        }
        else // 먹을것이 없으므로 엄마상어 호출
        {
            break;
        }
    }

    cout << ans << "\n";

    return 0;
}
