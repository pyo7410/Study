#include <iostream>
#include <cstring>
using namespace std;

int n;
int d[101][101];

// 그래프상 점은 한개 뿐이므로
bool visited[101];

void dfs(int idx)
{
    for (int j = 1; j <= n; ++j)
    {
        if (d[idx][j] == 1 && !visited[j])
        {
            visited[j] = true;
            dfs(j);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cin >> d[i][j];
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        // 열마다 각각 visited를 사용하므로 초기화가 필요
        memset(visited, false, sizeof(visited));

        // 열마다 dfs를 진행
        // 그래프상에서는 한개의 점뿐이므로
        dfs(i);

        for (int j = 1; j <= n; ++j)
        {
            if (visited[j])
            {
                d[i][j] = 1;
            }
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cout << d[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}