#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    for (int cnt = 1; cnt <= 10; ++cnt)
    {
        int t;
        cin >> t;

        int arr[100][100] = {0, };

        for (int i = 0; i < 100; ++i)
        {
            for (int j = 0; j < 100; ++j)
            {
                cin >> arr[i][j];
            }
        }

        int ans = -1;

        for (int i = 0; i < 100; ++i)
        {
            int row_sum = 0;
            int column_sum = 0;
            for (int j = 0; j < 100; ++j)
            {
                row_sum += arr[i][j];
                column_sum += arr[j][i];
            }
            ans = max({row_sum, column_sum, ans});
        }

        int r_sum = 0;
        int l_sum = 0;
        for (int i = 0; i < 100; ++i)
        {
            r_sum += arr[i][i];
            l_sum += arr[99 - i][99 - i];
        }
        ans = max({r_sum, l_sum, ans});

        cout << "#" << cnt << " " << ans << "\n";
    }

    return 0;
}
