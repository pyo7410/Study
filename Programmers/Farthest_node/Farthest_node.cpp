#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int visited[20001];

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    int max = 0;
    
    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < edge.size(); ++i)
    {
        graph[edge[i][0]].push_back(edge[i][1]);
        graph[edge[i][1]].push_back(edge[i][0]);
    }

    queue<int> q;
    q.push(1);
    visited[1] = 1;

    while (!q.empty())
    {
        int x = q.front();
        q.pop();

        for (int i = 0; i < graph[x].size(); ++i)
        {
            int y = graph[x][i];

            if (!visited[y])
            {
                visited[y] = visited[x] + 1;

                if (max < visited[y])
                {
                    max = visited[y];
                }

                q.push(y);
            }
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        if (visited[i] == max)
        {
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

    

    int m;
    cin >> m;
    vector<vector<int>> edge(m, vector<int>(2));
    for (int i = 0; i < m; ++i)
    {
        int x, y;
        cin >> x >> y;
        edge[i][0] = x;
        edge[i][1] = y;
    }

    cout << solution(n, edge) << "\n";
}