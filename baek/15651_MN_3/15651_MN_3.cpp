#include <iostream>
using namespace std;

int a[8];

void go(int index, int n, int m)
{
    if (index == m)
    {
        for (int i = 0; i < m; ++i)
        {
            cout << a[i] << " ";
        }
        cout << "\n";
        return;
    }
    for (int i = 1; i <= n; ++i)
    {
        a[index] = i;
        go(index + 1, n, m);
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    go(0, n, m);

}
