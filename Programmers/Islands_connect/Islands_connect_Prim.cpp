#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <queue>
using namespace std;

// cost, 현재 노드, 연결된 노드
using ti3 = tuple<int, int, int>;
bool chk[101];

// cost, index
vector<pair<int, int>> adj[101];

int solution(int n, vector<vector<int>> costs) 
{
    int answer = 0;
    int cnt = 0;
    // 간선의 cost 순으로 오름차순
    priority_queue<ti3, vector<ti3>, greater<ti3>> pq;

    for (auto cost : costs)
    {
        adj[cost[0]].push_back({cost[2], cost[1]});
        adj[cost[1]].push_back({cost[2], cost[0]});
    }

    // 0번과 연결된 간선을 q에 전부 삽입한다.
    for (auto nxt : adj[0])
    {
        pq.push({nxt.first, 0, nxt.second});
    }
    // 0번 노드는 MST에 포함됬으므로
    chk[0] = true;

    // cnt가 간선의 수 - 1 이 될때까지 즉, MST를 다 찾을때까지 반복
    while (1)
    {
        int cost, v1, v2;
        tie(cost, v1, v2) = pq.top();
        pq.pop();

        // 연결된 노드가 MST에 포함되있다면
        if (chk[v2])
        {
            continue;
        }

        // v2는 MST에 추가해야하므로
        chk[v2] = true;

        // 현재 가중치를 정답에 포함
        answer += cost;
        cnt++;

        // MST를 다 찾았다면
        if (cnt == n - 1)
        {
            break;
        }

        // v2와 연결된 모든 간선들을 pq에 삽입
        for (auto nxt : adj[v2])
        {
            // v2와 연결된 노드가 MST일 경우 제외
            if (!chk[nxt.second])
            {
                pq.push({nxt.first, v2, nxt.second});
            }
        }
    }

    return answer;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> costs(m, vector<int>(3));

    for (int i = 0; i < m; ++i)
    {
        cin >> costs[i][0] >> costs[i][1] >> costs[i][2];
    }

    cout << solution(n, costs) << "\n";

    return 0;
}