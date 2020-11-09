#include <iostream>
#include <queue>
using namespace std;

int arr[1001][1001];
int n, m;

bool dfs(int y, int x)
{
    if (x < 0 || y < 0 || x >= m || y >= n)
    {
        return false;
    }

    if (arr[y][x] == 0)
    {
        arr[y][x] = 1;

        dfs(x - 1, y);
        dfs(x, y - 1);
        dfs(x + 1, y);
        dfs(x, y + 1);

        return true;
    }

    return false;
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            scanf("%1d", &arr[i][j]);
        }
    }

    int answer = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (dfs(i, j))
            {
                answer++;
            }
        }
    }

    cout << answer << "\n";

    return 0;
}