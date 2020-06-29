#include <iostream>
#include <queue>
using namespace std;

// 문제에서 1번칸 부터라 했으니 1번칸으로 하자
// 왜 0번부터는 안되는지는 모르겠다..

int dist[101];     // 거리
int next_col[101]; // 다음 칸

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= 100; ++i)
    {
        dist[i] = -1;     // 거리 초기화
        next_col[i] = i;  // 다음 칸 초기화, 사다리와 뱀을 제외하고는 다음칸으로 이동 X
    }

    while (n--) // 사다리 정보 입력
    {
        int x, y;
        cin >> x >> y;
        next_col[x] = y;
    }

    while (m--) // 뱀 정보 입력
    {
        int x, y;
        cin >> x >> y;
        next_col[x] = y;
    }

    dist[1] = 0;

    queue<int> q;
    q.push(1);

    while (!q.empty()) // bfs
    {
        int x = q.front();
        q.pop();

        for (int i = 1; i <= 6; ++i)
        {
            int y = x + i; // 주사위 칸 만큼 이동

            if (y > 100) // 100보다 클 경우를 방지
            {
                continue;
            }

            y = next_col[y];
            if (dist[y] == -1) // 한번도 방문안한 점이라면
            {
                dist[y] = dist[x] + 1; // 이전 점에서 1번 이동했으므로
                q.push(y);             // 현재 칸을 queue에 push
            }
        }
    }

    cout << dist[100] << "\n";
    
    return 0;
}
