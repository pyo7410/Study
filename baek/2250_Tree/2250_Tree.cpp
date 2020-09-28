#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

int n;
vector<vector<int>> adj(10001);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        int node, l, r;
        cin >> node >> l >> r;

        adj[node].push_back(l);
        adj[node].push_back(r);
    }

    return 0;
}