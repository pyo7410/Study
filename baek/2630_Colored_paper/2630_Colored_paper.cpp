#include <iostream>
using namespace std;

int a[129][129];
int white_paper, blue_paper;

// 큰 사각형은 한개의 종이로 쳐야한다!

void solve(int x, int y, int n)
{
    int cnt = 0;
    for (int i = x; i < x + n; ++i)
    {
        for (int j = y; j < y + n; ++j)
        {
            // 1이 있다면
            if (a[i][j])
            {
                cnt++;
            }
        }
    }

    if (!cnt) // 1이 하나도 없다면
    {
        white_paper++;
    }
    else if (cnt == n * n) // x, y 부터 n 크기인 사각형이 전부 1이라면
    {
        blue_paper++;
    }
    else // 1과 0 이 같이 존재한다면
    {
        solve(x, y, n / 2);
        solve(x, y + (n / 2), n / 2);
        solve(x + (n / 2), y, n / 2);
        solve(x + (n / 2), y + (n / 2), n / 2);
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
    solve(0, 0, n);

    cout << white_paper << "\n";
    cout << blue_paper << "\n";

    return 0;
}