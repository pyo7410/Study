#include <iostream>
#include <queue>
using namespace std;

int h_dx[] = {2, 2, 1, 1, -1, -1, -2, -2};
int h_dy[] = {1, -1, 2, -2, 2, -2, 1, -1};

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int k, w, h;
int arr[201][201];

// queue에 남은 능력 개수를 넣지 않으면 능력의 수는
// 갱신되지 않고 다른 경로에서 사용한 값이 그대로 사용되므로
// 답이 안나온다.
// 그러므로 visited에 하나의 차원을 더 추가해 남은 능력에 따른 방문을 체크한다
bool visited[201][201][31];

void bfs()
{
    // a, b, 움직인 횟수, 말처럼 움직인 횟수
    queue<pair<pair<int, int>, pair<int, int>>> q;
    q.push({{1, 1}, {0, 0}});

    // a, b, 남은 능력의 수
    visited[1][1][0] = true;

    // 1, 1에서 시작하도록 했으므로 queue에 처음 넣을때와 visited를 처음 갱신할때
    // 0, 0이 아닌 1, 1로 하는것을 주의

    while (!q.empty())
    {
        int x = q.front().first.first;
        int y = q.front().first.second;

        int cnt = q.front().second.first;
        int h_cnt = q.front().second.second;
        
        q.pop();

        // 끝에 도달했을 경우
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
                    // nx, ny로 움직였더라도 경로에 따라 남은 능력의 수가 전부 달라진다!
                    // 그러므로 visited에 하나의 차원을 더 추가해 남은 능력에 따른 방문을 체크한다
                    if (!visited[nx][ny][h_cnt + 1] && arr[nx][ny] == 0)
                    {
                        visited[nx][ny][h_cnt + 1] = true;

                        // arr[nx][ny] = arr[x][y] + 1을 안하는이유는 arr[x][y]가 0이면 arr[nx][ny]는 1이 되고
                        // 1이 장애물이기 때문에 겹치게 되므로 쓰지 않는다
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
                // nx, ny로 움직였더라도 경로에 따라 남은 능력의 수가 전부 달라진다!
                // 그러므로 visited에 하나의 차원을 더 추가해 남은 능력에 따른 방문을 체크한다

                // 일반 이동시에는 능력을 쓰지 않으므로 h_cnt + 1을 하지 않고 그대로 비교한다!
                if (!visited[nx][ny][h_cnt] && arr[nx][ny] == 0)
                {
                    visited[nx][ny][h_cnt] = true;

                    // arr[nx][ny] = arr[x][y] + 1을 안하는이유는 arr[x][y]가 0이면 arr[nx][ny]는 1이 되고
                    // 1이 장애물이기 때문에 겹치게 되므로 쓰지 않는다

                    // 일반 이동시에는 능력을 쓰지 않으므로 h_cnt + 1을 하지 않고 그대로 비교한다!
                    q.push({{nx, ny}, {cnt + 1, h_cnt}});
                }
            }
        }
    }

    // while문에서 빠져나왔다면
    // 끝까지 가지 못한것!
    cout << -1 << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> k;
    cin >> w >> h;

    // h는 높이 w는 너비이므로
    // i는 h, j는 w 까지 반복
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
