#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

bool visited[201];

int solution(int n, vector<vector<int>> computers) 
{
    int answer = 0;
    queue<int> q;

    // computers에는 그래프들의 연결 정보가 들어있음을 주의!
    // 즉, 1차원
    for (int i = 0; i < n; ++i)
    {
        // 네트워크이므로 이미 방문한 컴퓨터는 방문할 필요가 없다.
        if (!visited[i])
        {
            q.push(i);
            visited[i] = true;

            // bfs가 일어나는 실질 구간!
            while (!q.empty())
            {
                int x = q.front();
                q.pop();

                for (int j = 0; j < n; ++j)
                {
                    if (!visited[j] && computers[x][j] == 1)
                    {
                        visited[j] = true;
                        q.push(j);
                    }
                }
            }

            // 방문안한 컴퓨터이므로
            // 즉, bfs가 안거친 구간이므로 다른 네트워크이다.
            answer++;
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

    vector<vector<int>> computers(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> computers[i][j];
        }
    }

    cout << solution(n, computers) << endl;
}