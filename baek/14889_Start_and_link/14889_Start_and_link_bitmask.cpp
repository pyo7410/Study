#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int s[20][20];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int n, t1, t2, diff;
    int ans = -1;
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> s[i][j];
        }
    }

    for (int i = 1; i < (1 << n); ++i)
    {
        vector<int> first, second;
        for (int j = 0; j < n; ++j)
        {
            if (i & (1 << j))
            {
                first.push_back(j);
            }
            else
            {
                second.push_back(j);
            }
        }
        if (first.size() != n / 2)
        {
            continue;
        }
        t1 = 0;
        t2 = 0;

        for (int l1 = 0; l1 < n / 2; ++l1)
        {
            for (int l2 = 0; l2 < n / 2; ++l2)
            {
                if (l1 == l2)
                {
                    continue;
                }
                t1 += s[first[l1]][first[l2]];
                t2 += s[second[l1]][second[l2]];
            }
        }
        
        diff = t1 - t2;
        if (diff < 0)
        {
            diff = -diff;
        }
        if (ans == -1 || ans > diff)
        {
            ans = diff;
        }
    }

    cout << ans << "\n";
    
    return 0;
}
