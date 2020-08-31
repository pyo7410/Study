#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

// https://dev-mb.tistory.com/58

// 왼쪽 오른쪽 전부 check
// 기준점에서
// 0 : -, 1 : |
int visited[101][101][2];

int board_size;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

bool moveCheck(int nx, int ny, int dir)
{
    // 가로
    // 가로의 경우 왼쪽 좌표만 있으므로 오른쪽 좌표까지 고려해야한다.
    if (dir == 0 && (nx < 0 || ny < 0 || nx + 1 >= board_size || ny >= board_size))
    {
        return false;
    }

    // 세로
    // 세로의 경우 위쪽 좌표만 있으므로 아래쪽 좌표까지 고려해야 한다.
    if (dir == 1 && (nx < 0 || ny < 0 || nx >= board_size || ny + 1 >= board_size))
    {
        return false;
    }
    return true;
}

bool turnCheck(int x, int y)
{
    if (x >= 0 && y >= 0 && x < board_size && y < board_size)
    {
        return true;
    }
    return false;
}

class Robot
{
public:
    int x;
    int y;
    int dir;

    Robot(int x, int y, int dir)
    {
        this->x = x;
        this->y = y;
        this->dir = dir;
    }
};

int solution(vector<vector<int>> board)
{
    int answer = 0;
    board_size = board.size();

    // x, y, dir
    // dir -> 0 : 가로, 1 : 세로
    // 큐에는 가로일경우 왼쪽의 좌표가
    // 세로일 경우에는 위쪽의 좌표가 들어간다.
    queue<Robot> q;
    q.push(Robot(0, 0, 0));
    visited[0][0][0] = 1;

    while (!q.empty())
    {
        // x, y를 배열의 인덱스로 본다!
        int x = q.front().x;
        int y = q.front().y;
        int dir = q.front().dir;
        q.pop();

        // 어느쪽이든 마지막칸이면 종료
        // 가로
        if (dir == 0 && x + 1 == (board_size - 1) && y == (board_size - 1))
        {
            answer = visited[y][x][dir] - 1;
            break;
        }
        // 세로
        if (dir == 1 && x == (board_size - 1) && y + 1 == (board_size - 1))
        {
            answer = visited[y][x][dir] - 1;
            break;
        }

        // 회전 없이 상하좌우 이동
        for (int i = 0; i < 4; ++i)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // 가로
            if (dir == 0 && visited[ny][nx][dir] == 0 && board[ny][nx] == 0 && board[ny][nx + 1] == 0)
            {
                visited[ny][nx][dir] = visited[y][x][dir] + 1;
                q.push(Robot(nx, ny, dir));
            }

            // 세로
            if (dir == 1 && visited[ny][nx][dir] == 0 && board[ny][nx] == 0 && board[ny + 1][nx] == 0)
            {
                visited[ny][nx][dir] = visited[y][x][dir] + 1;
                q.push(Robot(nx, ny, dir));
            }
        }

        // 가로방향일때 회전
        // 회전하면 가로는 세로로 바뀌게 되므로 dir의 값을 0 -> 1, 1 -> 0으로 바꿔준다
        if (dir == 0)
        {
            // 주의!! x, y를 인덱스로 봐야한다!
            // 왼쪽이 축이고 위방향 회전
            // 이 경우 오른쪽이 위로 가기때문에 세로의 경우 로봇의 위 부분을 큐에 넣어야하므로
            // 갱신된 부분을 위에 넣는다
            if (turnCheck(x, y - 1))
            {
                if (board[y - 1][x] == 0 && board[y - 1][x + 1] == 0)
                {
                    if (visited[y - 1][x][!dir] == 0)
                    {
                        visited[y - 1][x][!dir] = visited[y][x][dir] + 1;
                        q.push(Robot(x, y - 1, !dir));
                    }
                }
            }
            // 왼쪽이 축이고 아래방향 회전
            // 이 경우 왼쪽이 세로로 바뀌게되고 dir을 알고있으므로 위쪽으로 바뀌어도 좌표는 변함없으니 큐에는 그대로 넣어준다.
            // 신경쓸 필요가 없다!
            if (turnCheck(x, y + 1))
            {
                if (board[y + 1][x] == 0 && board[y + 1][x + 1] == 0)
                {
                    if (visited[y][x][!dir] == 0)
                    {
                        visited[y][x][!dir] = visited[y][x][dir] + 1;
                        q.push(Robot(x, y, !dir));
                    }
                }
            }

            // 오른쪽이 축이고 위방향 회전
            // 이때 회전축은 오른쪽이지만 x, y는 왼쪽이라는 점을 유의하자!
            // 이 경우 왼쪽이 위로 가기때문에 좌표가 바뀌어 세로의 경우 로봇의 위부분을 큐에 넣어야한다.
            if (turnCheck(x + 1, y - 1))
            {
                if (board[y - 1][x + 1] == 0 && board[y - 1][x] == 0)
                {
                    if (visited[y - 1][x + 1][!dir] == 0)
                    {
                        visited[y - 1][x + 1][!dir] = visited[y][x][dir] + 1;
                        q.push(Robot(x + 1, y - 1, !dir));
                    }
                }
            }

            // 오른쪽이 축이고 아래방향 회전
            // 이때 회전축은 오른쪽이지만 x, y는 왼쪽이라는 점을 유의하자!
            // 이 경우 왼쪽이 아래로 가기때문에 세로의 경우 로봇의 위부분을 큐에 넣어야한다.
            if (turnCheck(x + 1, y + 1))
            {
                if (board[y + 1][x + 1] == 0 && board[y + 1][x] == 0)
                {
                    if (visited[y][x + 1][!dir] == 0)
                    {
                        visited[y][x + 1][!dir] = visited[y][x][dir] + 1;
                        q.push(Robot(x + 1, y, !dir));
                    }
                }
            }
        }

        // 세로 방향일 경우
        // 항상 위쪽의 좌표가 기준이라는 것을 잊지말자
        if (dir == 1)
        {
            // 위쪽을 기준으로 왼쪽방향 회전
            // 이 경우 아래쪽이 왼쪽으로 가게 되므로 큐에는 왼쪽을 넣어야함을 주의
            if (turnCheck(x - 1, y))
            {
                if (board[y + 1][x - 1] == 0 && board[y][x - 1] == 0)
                {
                    if (visited[y][x - 1][!dir] == 0)
                    {
                        visited[y][x - 1][!dir] = visited[y][x][dir] + 1;
                        q.push(Robot(x - 1, y, !dir));
                    }
                }
            }
            // 위쪽을 기준으로 오른쪽방향 회전
            // 이 경우 아래쪽이 오른쪽으로 가게 되고 dir을 알고있으므로 왼쪽으로 바뀌어도 좌표는 변함없으니 큐에는 그대로 넣어준다.
            if (turnCheck(x + 1, y))
            {
                if (board[y + 1][x + 1] == 0 && board[y][x + 1] == 0)
                {
                    if (visited[y][x][!dir] == 0)
                    {
                        visited[y][x][!dir] = visited[y][x][dir] + 1;
                        q.push(Robot(x, y, !dir));
                    }
                }
            }

            // 아래쪽을 기준으로 왼쪽방향 회전
            // 이 경우 위쪽이 왼쪽으로 가게되지만 dir을 알고있어도 좌표가 달라지므로 변한 좌표를 큐에 넣어준다.
            if (turnCheck(x - 1, y + 1))
            {
                if (board[y + 1][x - 1] == 0 && board[y][x - 1] == 0)
                {
                    if (visited[y + 1][x - 1][!dir] == 0)
                    {
                        visited[y + 1][x - 1][!dir] = visited[y][x][dir] + 1;
                        q.push(Robot(x - 1, y + 1, !dir));
                    }
                }
            }
            // 아래쪽을 기준으로 오른쪽방향 회전
            // 이 경우 위쪽이 오른쪽으로 가게되고 아래쪽 좌표가 왼쪽이 되므로 아래쪽 좌표를 큐에 넣어준다.
            if (turnCheck(x + 1, y + 1))
            {
                if (board[y + 1][x + 1] == 0 && board[y][x + 1] == 0)
                {
                    if (visited[y + 1][x][!dir] == 0)
                    {
                        visited[y + 1][x][!dir] = visited[y][x][dir] + 1;
                        q.push(Robot(x, y + 1, !dir));
                    }
                }
            }
        }
    }

    return answer;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> board(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> board[i][j];
        }
    }

    cout << solution(board) << endl;

    return 0;
}
