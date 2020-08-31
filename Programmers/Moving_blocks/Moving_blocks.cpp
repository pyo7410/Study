#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

// https://dev-mb.tistory.com/58

// ���� ������ ���� check
// ����������
// 0 : -, 1 : |
int visited[101][101][2];

int board_size;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

bool moveCheck(int nx, int ny, int dir)
{
    // ����
    // ������ ��� ���� ��ǥ�� �����Ƿ� ������ ��ǥ���� ����ؾ��Ѵ�.
    if (dir == 0 && (nx < 0 || ny < 0 || nx + 1 >= board_size || ny >= board_size))
    {
        return false;
    }

    // ����
    // ������ ��� ���� ��ǥ�� �����Ƿ� �Ʒ��� ��ǥ���� ����ؾ� �Ѵ�.
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
    // dir -> 0 : ����, 1 : ����
    // ť���� �����ϰ�� ������ ��ǥ��
    // ������ ��쿡�� ������ ��ǥ�� ����.
    queue<Robot> q;
    q.push(Robot(0, 0, 0));
    visited[0][0][0] = 1;

    while (!q.empty())
    {
        // x, y�� �迭�� �ε����� ����!
        int x = q.front().x;
        int y = q.front().y;
        int dir = q.front().dir;
        q.pop();

        // ������̵� ������ĭ�̸� ����
        // ����
        if (dir == 0 && x + 1 == (board_size - 1) && y == (board_size - 1))
        {
            answer = visited[y][x][dir] - 1;
            break;
        }
        // ����
        if (dir == 1 && x == (board_size - 1) && y + 1 == (board_size - 1))
        {
            answer = visited[y][x][dir] - 1;
            break;
        }

        // ȸ�� ���� �����¿� �̵�
        for (int i = 0; i < 4; ++i)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // ����
            if (dir == 0 && visited[ny][nx][dir] == 0 && board[ny][nx] == 0 && board[ny][nx + 1] == 0)
            {
                visited[ny][nx][dir] = visited[y][x][dir] + 1;
                q.push(Robot(nx, ny, dir));
            }

            // ����
            if (dir == 1 && visited[ny][nx][dir] == 0 && board[ny][nx] == 0 && board[ny + 1][nx] == 0)
            {
                visited[ny][nx][dir] = visited[y][x][dir] + 1;
                q.push(Robot(nx, ny, dir));
            }
        }

        // ���ι����϶� ȸ��
        // ȸ���ϸ� ���δ� ���η� �ٲ�� �ǹǷ� dir�� ���� 0 -> 1, 1 -> 0���� �ٲ��ش�
        if (dir == 0)
        {
            // ����!! x, y�� �ε����� �����Ѵ�!
            // ������ ���̰� ������ ȸ��
            // �� ��� �������� ���� ���⶧���� ������ ��� �κ��� �� �κ��� ť�� �־���ϹǷ�
            // ���ŵ� �κ��� ���� �ִ´�
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
            // ������ ���̰� �Ʒ����� ȸ��
            // �� ��� ������ ���η� �ٲ�Եǰ� dir�� �˰������Ƿ� �������� �ٲ� ��ǥ�� ���Ծ����� ť���� �״�� �־��ش�.
            // �Ű澵 �ʿ䰡 ����!
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

            // �������� ���̰� ������ ȸ��
            // �̶� ȸ������ ������������ x, y�� �����̶�� ���� ��������!
            // �� ��� ������ ���� ���⶧���� ��ǥ�� �ٲ�� ������ ��� �κ��� ���κ��� ť�� �־���Ѵ�.
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

            // �������� ���̰� �Ʒ����� ȸ��
            // �̶� ȸ������ ������������ x, y�� �����̶�� ���� ��������!
            // �� ��� ������ �Ʒ��� ���⶧���� ������ ��� �κ��� ���κ��� ť�� �־���Ѵ�.
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

        // ���� ������ ���
        // �׻� ������ ��ǥ�� �����̶�� ���� ��������
        if (dir == 1)
        {
            // ������ �������� ���ʹ��� ȸ��
            // �� ��� �Ʒ����� �������� ���� �ǹǷ� ť���� ������ �־������ ����
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
            // ������ �������� �����ʹ��� ȸ��
            // �� ��� �Ʒ����� ���������� ���� �ǰ� dir�� �˰������Ƿ� �������� �ٲ� ��ǥ�� ���Ծ����� ť���� �״�� �־��ش�.
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

            // �Ʒ����� �������� ���ʹ��� ȸ��
            // �� ��� ������ �������� ���Ե����� dir�� �˰��־ ��ǥ�� �޶����Ƿ� ���� ��ǥ�� ť�� �־��ش�.
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
            // �Ʒ����� �������� �����ʹ��� ȸ��
            // �� ��� ������ ���������� ���Եǰ� �Ʒ��� ��ǥ�� ������ �ǹǷ� �Ʒ��� ��ǥ�� ť�� �־��ش�.
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
