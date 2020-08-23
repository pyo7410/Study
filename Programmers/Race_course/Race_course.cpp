#include <iostream>
#include <string>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

// ??? ??? ???? ???? ?? ???? ??
// ?, ?????? ???? ???? ?? ???? ???? ??
int visited[26][26][5]; // 0 : ??, 1 : ?, 3 : ?, 4 : ?

int solution(vector<vector<int>> board)
{
    int answer = INF;
    int board_size = board.size();

    // i, j? 1???? j? 0??? ? ??? ?????? ??
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

    // ???? ???
    for (int i = 0; i < 4; ++i)
    {
        visited[0][0][i] = 0;
    }

    // x, y ??, ??
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
                    // ??? ???
                    if (cur_dir == k)
                    {
                        if (visited[nx][ny][k] > visited[x][y][cur_dir] + 100)
                        {
                            visited[nx][ny][k] = visited[x][y][cur_dir] + 100;
                            q.push({{nx, ny}, k});
                        }
                    }
                    else // ??? ????
                    {
                        // ??? ?? ??? ???? ??? ??????? ??? ????? ??? ???
                        // ???? 500 + 100? ??.
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

    // ??? ???? ??? ???? ???? ??
    for (int i = 0; i < 4; ++i)
    {
        if (answer > visited[board_size - 1][board_size - 1][i])
        {
            answer = visited[board_size - 1][board_size - 1][i];
        }
    }

    // ?? ??? ??? 0?? ???? 0? ???? ??? ????? ??????
    // ??????? ?????? ?? ????? 3?? ??? ??? 3? ???? ??? 500?? ?????.
    return answer - 500;
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

    cout << solution(board) << "\n";

    return 0;
}
