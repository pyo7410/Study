#include <iostream>
using namespace std;

int a[2188][2188];
int ans[3];

void solve(int x, int y, int n)
{
    // 순서대로 -1, 0, 1 카운트
    int cnt_minus_1 = 0, cnt_0 = 0, cnt_1 = 0;
    for (int i = y; i < y + n; ++i)
    {
        for (int j = x; j < x + n; ++j)
        {
            if (a[i][j] == -1)
            {
                cnt_minus_1++;
            }
            else if (a[i][j] == 0)
            {
                cnt_0++;
            }
            else if (a[i][j] == 1)
            {
                cnt_1++;
            }
        }
    }

    if (cnt_minus_1 == n * n) // x, y 부터 n 크기인 사각형이 전부 -1이라면
    {
        ans[0]++;
    }
    else if (cnt_0 == n * n) // x, y 부터 n 크기인 사각형이 전부 0이라면
    {
        ans[1]++;
    }
    else if (cnt_1 == n * n) // x, y 부터 n 크기인 사각형이 전부 1이라면
    {
        ans[2]++;
    }
    else // -1, 0, 1이 같이 존재한다면
    {
        // y 축 기준 1 / 3 했을때 맨 윗칸
        solve(x, y, n / 3);
        solve(x + (n / 3), y, n / 3);
        solve(x + (n - (n / 3)), y, n / 3);

        // y 축 기준 1 / 3 했을때 가운데칸
        solve(x, y + (n / 3), n / 3);
        solve(x + (n / 3), y + (n / 3), n / 3);
        solve(x + (n - (n / 3)), y + (n / 3), n / 3);

        // y 축 기준 1 / 3 했을때 맨 아래칸
        solve(x, y + (n - (n / 3)), n / 3);
        solve(x + (n / 3), y + (n - (n / 3)), n / 3);
        solve(x + (n - (n / 3)), y + (n - (n / 3)), n / 3);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> a[i][j];
        }
    }
    
    // 첫 시작 점
    // i, j, n x n 을 나타내는 n
    solve(0, 0, n);

    for (int i = 0; i < 3; ++i)
    {
        cout << ans[i] << "\n";
    }

    return 0;
}