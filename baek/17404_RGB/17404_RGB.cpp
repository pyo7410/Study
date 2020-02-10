#include <iostream>
#include <algorithm>
using namespace std;

#define INF 1000 * 1000 + 1;

int d[1001][3];
int a[1001][3];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int n;
    int ans = INF;
    cin >> n;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j <= 2; ++j)
        {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i <= 2; ++i)
    {
        for (int j = 0; j <= 2; ++j)
        {
            if (i == j)
            {
                d[1][j] = a[1][j];
            }
            else
            {
                d[1][j] = INF;
            }
            
        }
        
        for (int j = 2; j <= n; ++j)
        {
            d[j][0] = min(d[j - 1][1], d[j - 1][2]) + a[j][0];
            d[j][1] = min(d[j - 1][0], d[j - 1][2]) + a[j][1];
            d[j][2] = min(d[j - 1][0], d[j - 1][1]) + a[j][2];
        }

        for (int j = 0; j <= 2; ++j)
        {
            if (i == j) continue; // 첫번째 색상과 같으므로 넘기기위함
            ans = min(ans, d[n][j]);
        }
    }

    cout << ans << "\n";
}
