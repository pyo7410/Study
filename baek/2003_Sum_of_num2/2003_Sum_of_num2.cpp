#include <iostream>
#include <algorithm>
using namespace std;

int a[10001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    int l = 0;
    int r = 0;
    int sum = 0;
    int cnt = 0;
    while (l <= r && r <= n)
    {
        if (sum >= m)
        {
            if (sum == m)
            {
                cnt++;
            }

            sum -= a[l];
            l++;
        }
        else
        {
            sum += a[r];
            r++;
        }
    }
    
    cout << cnt << "\n";

    return 0;
}