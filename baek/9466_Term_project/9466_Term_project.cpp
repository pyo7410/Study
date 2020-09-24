#include <iostream>
#include <cstring>
using namespace std;

int n, cnt;
bool visited[100001];
bool done[100001];
int a[100001];

void dfs(int i)
{
    visited[i] = true;

    int x = a[i];

    if (!visited[x])
    {
        dfs(x);
    }
    else if (!done[x]) // 방문은 했지만 해당 노드가 끝난 노드가 아니라면
    {
        // 싸이클이 생긴 노드들의 수를 센다.
        for (int j = x; j != i; j = a[j])
        {
            cnt++;
        }
        // 자기자신의 수도 카운트
        cnt++;
    }
    
    // 노드를 다시 방문할 필요가 없으므로
    done[i] = true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        memset(visited, false, sizeof(visited));
        memset(done, false, sizeof(done));

        cin >> n;

        // 문제에서 인덱스는 1부터 시작이므로 1부터 해야한다!
        for (int i = 1; i <= n; ++i)
        {
            cin >> a[i];
        }

        cnt = 0;
        // 문제에서 인덱스는 1부터 시작이므로 1부터 해야한다!
        for (int i = 1; i <= n; ++i)
        {
            if (!visited[i])
            {
                dfs(i);
            }
        }
        
        cout << n - cnt << "\n";
    }

    return 0;
}