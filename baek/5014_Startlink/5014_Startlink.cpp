#include <iostream>
#include <queue>
#define MAX 1000001
using namespace std;

int F, S, G, U, D;
int a[MAX];
bool visited[MAX];

class Info
{
public:
    int x;
    int cnt;

    Info(int x, int cnt)
    {
        this->x = x;
        this->cnt = cnt;
    }
};

int bfs()
{
    queue<Info> q;
    q.push(Info(S, 0));
    visited[S] = true;

    while (!q.empty())
    {
        int x = q.front().x;
        int cnt = q.front().cnt;
        q.pop();

        if (x == G)
        {
            return cnt;
        }

        // 마지막 층은 MAX가 아닌 F임을 주의!
        if (x + U <= F && !visited[x + U])
        {
            visited[x + U] = true;
            q.push(Info(x + U, cnt + 1));
        }
        if (x - D > 0 && !visited[x - D])
        {
            visited[x - D] = true;
            q.push(Info(x - D, cnt + 1));
        }
    }
    
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> F >> S >> G >> U >> D;

    int result = bfs();

    if (result == -1)
    {
        cout << "use the stairs\n";
    }
    else
    {
        cout << result << "\n";
    }

    return 0;
}