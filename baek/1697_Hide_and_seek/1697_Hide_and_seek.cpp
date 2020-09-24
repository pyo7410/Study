#include <iostream>
#include <queue>
using namespace std;

// 만약 100000을 벗어난다면
// *2 로 벗어날 확률이 큰데
// 그럴경우 다시 동생이 있는 100000안 으로 돌아올려면
// -1을 반복하는 방법밖에 없으므로 100000을 나가는것은 비효율적이고
// 정답을 찾는데 100000이면 충분하다.
int dist[100002];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k;
    cin >> n >> k;

    fill(dist, dist+100001, -1);

    // 현재 수빈이의 위치
    dist[n] = 0;

    queue<int> q;
    q.push(n);

    // 동생의 위치까지 갱신이 된다면
    while (dist[k] == -1)
    {
        int i = q.front();
        q.pop();

        for (int next_i : {i - 1, i + 1, i * 2})
        {
            // 다음 i 가 0보다 작거나 100000을 벗어나면
            if (next_i < 0 || next_i > 100000)
            {
                continue;
            }
            
            // 방문한 적이 있다면
            if (dist[next_i] != -1)
            {
                continue;
            }

            dist[next_i] = dist[i] + 1;
            q.push(next_i);
        }
    }

    cout << dist[k] << "\n";    

    return 0;
}