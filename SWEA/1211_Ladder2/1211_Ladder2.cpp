#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int arr[101][101] = {0, };

    for (int test_case = 1; test_case <= 10; ++test_case)
    {
        int t;
        cin >> t;

        int i, j;
        for (i = 0; i < 100; ++i)
        {
            for (int j = 0; j < 100; ++j)
            {
                cin >> arr[i][j];
            }
        }

        int min = 2147483647;
        int ans = 0;
        for (j = 0; j < 100; ++j)
        {
            if (arr[99][j] == 1)
            {
                int cnt = 0;

                int x = 100;
                int y = j;

                x = 100;
                while (x--)
                {
                    cnt += 1;
                    if (arr[x][y + 1])
                    {
                        while (y + 1 < 100 && arr[x][y + 1])
                        {
                            cnt += 1;
                            y += 1;
                        }
                    }
                    else if (y - 1 > 0 && arr[x][y - 1])
                    {
                        while (arr[x][y - 1])
                        {
                            cnt += 1;
                            y -= 1;
                        }
                    }
                }
                if (min > cnt)
                {
                    min = cnt;
                    ans = y;
                }
            }
        }

        cout << "#" << test_case << " " << ans << "\n";
    }

    return 0;
}
