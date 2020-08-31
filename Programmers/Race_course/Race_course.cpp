#include <string>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

// 마지막 차원은 방향을 저장
// 즉, 해당지점에서 올수있는 방향마다 값을 저장하여 비교할떄 사용
int visited[26][26][5]; // 0 : 아래, 1 : 위, 3 : 좌, 4 : 우

int solution(vector<vector<int>> board)
{
    int answer = INF;
    int board_size = board.size();

    for (int i = 0; i < board_size; ++i)
    {
        for (int j = 0; j < board_size; ++j)
        {
            for (int k = 0; k < 4; ++k)
            {
                visited[i][j][k] = INF;
            }
        }
    }

    for (int i = 0; i < 4; ++i)
    {
        visited[0][0][i] = 0;
    }

    // x, y 좌표, 방향
    queue<pair<pair<int, int>, int>> q;
    q.push({{0, 0}, 0});

    while (!q.empty())
    {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int cur_dir = q.front().second;
        q.pop();

        for (int k = 0; k < 4; ++k)
        {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (nx >= 0 && nx < board_size && ny >= 0 && ny < board_size)
            {
                if (!board[nx][ny])
                {
                    // 방향이 같다면
                    if (cur_dir == k)
                    {
                        if (visited[nx][ny][k] > visited[x][y][cur_dir] + 100)
                        {
                            visited[nx][ny][k] = visited[x][y][cur_dir] + 100;
                            q.push({{nx, ny}, k});
                        }
                    }
                    else // 방향이 다르다면
                    {
                        // 코너를 돌때 코너를 돌고나서 앞으로 직진해야하므로 코너와 직진도로를 동시에 만든다
                        // 그러므로 500 + 100이 된다.
                        if (visited[nx][ny][k] > visited[x][y][cur_dir] + 600)
                        {
                            visited[nx][ny][k] = visited[x][y][cur_dir] + 600;
                            q.push({{nx, ny}, k});
                        }
                    }
                }
            }
        }
    }

    for (int i = 0; i < 4; ++i)
    {
        if (answer > visited[board_size - 1][board_size - 1][i])
        {
            answer = visited[board_size - 1][board_size - 1][i];
        }
    }

    // 처음 시작때 방향을 0으로 했으므로 아랫방향에만 직진이되는데
    // 처음지점에서는 어느방향으로 가도 직진이므로 그때에 생기는 3 방향의 500원을 빼는것이다.
    return answer - 500;
}