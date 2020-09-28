#include <iostream>
#include <vector>
using namespace std;

bool check[100001];
vector<int> tree[100001];
int p[100001];

void dfs(int x)
{
    check[x] = true;

    for (int i = 0; i < tree[x].size(); ++i)
    {
        int nx = tree[x][i];

        if (check[nx])
        {
            continue;
        }

        p[nx] = x;
        dfs(nx);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n-1; i++) 
    {
		int a, b;
		cin >> a >> b;

		tree[a].push_back(b);
		tree[b].push_back(a);
	}
    
    dfs(1);

    // 1이 루트이므로
    for (int i = 2; i <= n; ++i)
    {
        cout << p[i] << "\n";
    }

    return 0;
}