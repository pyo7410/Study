#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

class Info
{
public:
    int x;
    int y;

    Info(int x, int y)
    {
        this->x = x;
        this->y = y;
    }

    Info()
    {
    }
};

bool visited[1001][1001];
string a[1001];
int n, m;
Info J_idx;
vector<Info> F_idx;

int bfs()
{
    int result = 1;

    queue<Info> J_q;
    queue<Info> F_q;

    J_q.push(J_idx);

    // 불의 시작위치들을 큐에 넣는다.
    for (int i = 0; i < F_idx.size(); ++i)
    {
        F_q.push(F_idx[i]);
    }

    // 지훈이의 이동경로가 없을때 까지 계속 반복!
    while (!J_q.empty())
    {
        // 불부터 1칸씩 이동시켜 준다.
        // 현재 큐에 들어있는 불의 위치만 옮기기 위해서
        // F_q의 사이즈를 매번 받아온다.
        int F_size = F_q.size();

        for (int i = 0; i < F_size; ++i)
        {
            int x = F_q.front().x;
            int y = F_q.front().y;
            F_q.pop();

            for (int j = 0; j < 4; ++j)
            {
                int nx = x + dx[j];
                int ny = y + dy[j];

                if (nx >= 0 && nx < m && ny >= 0 && ny < n)
                {
                    // 불은 옮기기만 하면되기에 방문여부는 상관없다!
                    if (a[ny][nx] == '.' || a[ny][nx] == 'J')
                    {
                        a[ny][nx] = 'F';
                        F_q.push(Info(nx, ny));
                    }
                }
            }
        }

        // 지훈이를 1칸 이동시켜 준다.
        // 지훈이도 마찬가지로 현재 큐에 들어있는 횟수만큼만
        // 이동하기 위해 매번 사이즈를 받아온다.
        int J_size = J_q.size();
        for (int i = 0; i < J_size; ++i)
        {
            int x = J_q.front().x;
            int y = J_q.front().y;
            J_q.pop();

            if (y == 0 || x == 0 || y == n - 1 || x == m - 1)
            {
                return result;
            }

            for (int j = 0; j < 4; ++j)
            {
                int nx = x + dx[j];
                int ny = y + dy[j];

                if (nx >= 0 && nx < m && ny >= 0 && ny < n)
                {
                    if (a[ny][nx] == '.' && !visited[ny][nx])
                    {
                        visited[ny][nx] = true;
                        J_q.push(Info(nx, ny));
                    }
                }
            }
        }

        // 한칸씩 이동했으니 +1
        result++;
    }

    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;

    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];

        for (int j = 0; j < a[i].length(); ++j)
        {
            if (a[i][j] == 'J')
            {
                J_idx = Info(j, i);
            }
            else if (a[i][j] == 'F')
            {
                F_idx.push_back(Info(j, i));
            }
        }
    }

    int result = bfs();

    if (result == -1)
    {
        cout << "IMPOSSIBLE\n";
    }
    else
    {
        cout << result << "\n";
    }
    
    return 0;
}