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

    m *= 2; // ģ�� ����� ������̹Ƿ�

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

            // ���� ����Ʈ���� first �� �ڱ� �ڽ��̰� second�� ������!
            // �� ���� �޶�� ģ�����谡 �ȴ�.
            if (A == B || A == C || A == D || B == C || B == D || C == D)
            {
                continue; // A, B�� C, D�� ���谡 ���ٸ� ���� �� �� �ʿ� X
            }

            // B, C
            if (!a[B][C])
            {
                continue; // B, C�� ���谡 ���ٸ� ���� �� �� �ʿ� X
            }
            // D, E
            for (int E : g[D]) // ��������Ʈ g[D]�� �ִ� ��� ��
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
