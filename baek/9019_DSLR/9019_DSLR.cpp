#include <iostream>
#include <queue>
#include <string>
#include <cstring>
using namespace std;

int dist[10001];
int from[10001];
bool check[10001];
char how[10001];

void print(int a, int b) {
    if (a == b)
    {
        return;
    }
    print(a, from[b]);
    cout << how[b];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int t;
    cin >> t;

    while(t--)
    {
        int a, b;
        cin >> a >> b;

        memset(dist, 0, sizeof(dist));
        memset(from, 0, sizeof(from));
        memset(how, 0, sizeof(how));
        memset(check, false, sizeof(check));

        dist[a] = 0;
        from[a] = -1; // 시작점 이므로 -1
        check[a] = true;
        
        queue<int> q;
        q.push(a);

        while (!q.empty())
        {
            int now = q.front();
            q.pop();

            // D 연산
            int next = (now * 2) % 10000;
            if (!check[next]) // 방문하지 않았다면
            {
                dist[next] = dist[now] + 1;
                from[next] = now;
                how[next] = 'D';
                check[next] = true;

                q.push(next);
            }
            
            // S 연산
            next = now - 1;
            if (next == -1)
            {
                next = 9999;
            }
            if (!check[next])
            {
                dist[next] = dist[now] + 1;
                from[next] = now;
                how[next] = 'S';
                check[next] = true;

                q.push(next);
            }

            // L 연산
            next = (now % 1000) * 10 + now / 1000;
            if (!check[next])
            {
                dist[next] = dist[now] + 1;
                from[next] = now;
                how[next] = 'L';
                check[next] = true;

                q.push(next);
            }

            // R 연산
            next = (now % 10) * 1000 + now / 10;
            if (!check[next])
            {
                dist[next] = dist[now] + 1;
                from[next] = now;
                how[next] = 'R';
                check[next] = true;

                q.push(next);
            }
        }

        print(a, b);
        cout << "\n";
    }
    
    return 0;
}
