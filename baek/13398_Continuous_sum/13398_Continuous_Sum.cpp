#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int n, ans;
    cin >> n;

    vector<int> d(n + 1);
    vector<int> d2(n + 1);
    vector<int> a(n + 1);

    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }

    d[1] = a[1];
    for (int i = 2; i <= n; ++i)
    {
        d[i] = a[i];
        if (d[i - 1] + a[i] > d[i])
        {
            d[i] = d[i - 1] + a[i];
        }
    }

    d2[n] = a[n];
    for (int i = n - 1; i > 0; --i)
    {
        d2[i] = a[i];
        if (d2[i + 1] + a[i] > d2[i])
        {
            d2[i] = d2[i + 1] + a[i];
        }
    }

    ans = d[1];
    for (int i = 2; i <= n; i++) 
    {
        if (ans < d[i]) 
        {
            ans = d[i];
        }
    }

    for (int i = 2; i < n; ++i)
    {
        if (ans < d[i - 1] + d2[i + 1])
        {
            ans = d[i - 1] + d2[i + 1];
        }
    }

    cout << ans << "\n";
}
