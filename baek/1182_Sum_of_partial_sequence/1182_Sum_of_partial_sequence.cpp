#include <iostream>
using namespace std;

int a[20];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int n, s, sum;
    int ans = 0;
    cin >> n >> s;

    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    for (int i = 1; i < (1 << n); ++i) // 공집합은 제외해야 하므로 1 부터 시작
    {
        sum = 0;
        for (int j = 0; j < n; ++j)
        {
            if (i & (1 << j)) 
            {
                sum += a[j];
            }
        }
        if (sum == s)
        {
            ans += 1;
        }
    }

    cout << ans << "\n";

    return 0;
}
