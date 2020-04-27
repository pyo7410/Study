#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool a[2000][2000];
vector<int> g[2000];
vector<pair<int, int>> edges;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int n, m;
    int from, to;
    cin >> n >> m;

    for (int i = 0; i < m; ++i)
    {
        cin >> from >> to;

        a[from][to] = true;
        a[to][from] = true;

        g[from].push_back(to);
        g[to].push_back(from);

        edges.push_back(make_pair(from, to));
        edges.push_back(make_pair(to, from));
    }

    m *= 2; // 친구 관계는 양방향이므로

    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            // A, B
            int A = edges[i].first;
            int B = edges[i].second;

            // C, D
            int C = edges[j].first;
            int D = edges[j].second;

            // 간선 리스트에서 first 는 자기 자신이고 second가 간선임!
            // 즉 값이 달라야 친구관계가 된다.
            if (A == B || A == C || A == D || B == C || B == D || C == D)
            {
                continue; // A, B와 C, D의 관계가 없다면 굳이 더 할 필요 X
            }

            // B, C
            if (!a[B][C])
            {
                continue; // B, C와 관계가 없다면 굳이 더 할 필요 X
            }
            // D, E
            for (int E : g[D]) // 인접리스트 g[D]에 있는 모든 값
            {
                if (A == E || B == E || C == E || D == E)
                {
                    continue;
                }
                cout << 1 << "\n";
                return 0;
            }
        }
    }

    cout << 0 << "\n";

    return 0;
}
