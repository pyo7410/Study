#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int a[500][500];

    int n, m;
    int temp, ans = 0;
    cin >> n >> m;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            // - 모양
            if (j + 3 < m)
            {
                temp = a[i][j] + a[i][j + 1] + a[i][j + 2] + a[i][j + 3];
                if (temp > ans)
                {
                    ans = temp;
                }
            }
            if (i + 3 < n)
            {
                temp = a[i][j] + a[i + 1][j] + a[i + 2][j] + a[i + 3][j];
                if (temp > ans)
                {
                    ans = temp;
                }
            }
            // □ 모양
            if (i + 1 < n && j + 1 < m)
            {
                temp = a[i][j] + a[i + 1][j] + a[i][j + 1] + a[i + 1][j + 1];
                if (temp > ans)
                {
                    ans = temp;
                }
            }
            // L 모양 (세로가 더 김)
            if (i + 2 < n && j + 1 < m)
            {
                temp = a[i][j] + a[i + 1][j] + a[i + 2][j] + a[i + 2][j + 1];
                if (temp > ans)
                {
                    ans = temp;
                }
            }
            if (i + 2 < n && j + 1 < m)
            {
                temp = a[i][j] + a[i + 1][j] + a[i + 2][j] + a[i][j + 1];
                if (temp > ans)
                {
                    ans = temp;
                }
            }
            if (i + 2 < n && j + 1 < m)
            {
                temp = a[i][j] + a[i + 1][j + 1] + a[i + 2][j + 1] + a[i][j + 1];
                if (temp > ans)
                {
                    ans = temp;
                }
            }
            if (i + 2 < n && j + 1 < m)
            {
                temp = a[i][j + 1] + a[i + 1][j + 1] + a[i + 2][j + 1] + a[i + 2][j];
                if (temp > ans)
                {
                    ans = temp;
                }
            }
            // --┐ 모양 (가로가 더 김)
            if (i + 1 < n && j + 2 < m)
            {
                temp = a[i][j] + a[i + 1][j] + a[i + 1][j + 1] + a[i + 1][j + 2];
                if (temp > ans)
                {
                    ans = temp;
                }
            }
            if (i + 1 < n && j + 2 < m)
            {
                temp = a[i][j] + a[i][j + 1] + a[i][j + 2] + a[i + 1][j];
                if (temp > ans)
                {
                    ans = temp;
                }
            }
            if (i + 1 < n && j + 2 < m)
            {
                temp = a[i][j] + a[i][j + 1] + a[i][j + 2] + a[i + 1][j + 2];
                if (temp > ans)
                {
                    ans = temp;
                }
            }
            if (i + 1 < n && j + 2 < m)
            {
                temp = a[i][j + 2] + a[i + 1][j] + a[i + 1][j + 1] + a[i + 1][j + 2];
                if (temp > ans)
                {
                    ans = temp;
                }
            }
            // ㄱㄴ 모양
            if (i + 1 < n && j + 2 < m)
            {
                temp = a[i][j] + a[i][j + 1] + a[i + 1][j + 1] + a[i + 1][j + 2];
                if (temp > ans)
                {
                    ans = temp;
                }
            }
            if (i + 1 < n && j + 2 < m)
            {
                temp = a[i][j + 1] + a[i][j + 2] + a[i + 1][j] + a[i + 1][j + 1];
                if (temp > ans)
                {
                    ans = temp;
                }
            }
             if (j+2 < m) {
                int temp = a[i][j] + a[i][j+1] + a[i][j+2];
                if (i-1 >= 0) {
                    int temp2 = temp + a[i-1][j+1];
                    if (ans < temp2) ans = temp2;
                }
                if (i+1 < n) {
                    int temp2 = temp + a[i+1][j+1];
                    if (ans < temp2) ans = temp2;
                }
            }
            if (i+2 < n) {
                int temp = a[i][j] + a[i+1][j] + a[i+2][j];
                if (j+1 < m) {
                    int temp2 = temp + a[i+1][j+1];
                    if (ans < temp2) ans = temp2;
                }
                if (j-1 >= 0) {
                    int temp2 = temp + a[i+1][j-1];
                    if (ans < temp2) ans = temp2;
                }
            }
        }
    }
    cout << ans << "\n";
}
