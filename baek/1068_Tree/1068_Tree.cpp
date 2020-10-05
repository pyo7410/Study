#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> adj[51];
int n, root, answer, remove_node;
bool visit[51];

void bfs(int node)
{
    queue<int> q;
    q.push(node);
    visit[node] = true;

    while (!q.empty())
    {
        int cur_node = q.front();
        q.pop();

        int child_cnt = 0;
        for (int i = 0; i < adj[cur_node].size(); ++i)
        {
            int nxt_node = adj[cur_node][i];

            if (!visit[nxt_node])
            {
                child_cnt++;
                visit[nxt_node] = true;
                q.push(nxt_node);
            }
        }

        // 자식이 한개도 없으면 리프노드 이므로
        if (child_cnt == 0)
        {
            answer++;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, root;
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        int v1;
        cin >> v1;

        if (v1 != -1)
        {
            adj[v1].push_back(i);
            adj[i].push_back(v1);
        }
        else
        {
            root = i;
        }
    }

    cin >> remove_node;

    // 방문 처리하여 해당 노드의 자식을 탐색하지 않게한다.
    visit[remove_node] = true;
    
    // root 에서부터 bfs를 수행하면서 리프노드를
    // 찾는다.
    if (!visit[root])
    {
        bfs(root);
    }

    cout << answer << "\n";

    return 0;
}