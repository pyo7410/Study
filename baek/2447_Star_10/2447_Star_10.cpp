#include <iostream>
#include <cstring>
using namespace std;

char arr[3000][3000];

/*
void solve(int x, int y, int n)
{
    if (n == 3)
    {
        int count = 0;

        for (int i = y; i < y + n; ++i)
        {
            for (int j = x; j < x + n; ++j)
            {
                if (count != 4)
                {
                    arr[i][j] = '*';
                }
                count++;
            }
        }

        return;
    }

    solve(x, y, n / 3);
    solve(x + (n / 3), y, n / 3);
    solve(x + (n - (n / 3)), y, n / 3);

    solve(x, y  + (n / 3), n / 3);
    // 한 가운데는 제외
    // solve(x + (n / 3), y  + (n / 3), n / 3);
    solve(x + (n - (n / 3)), y  + (n / 3), n / 3);

    solve(x, y + (n - (n / 3)), n / 3);
    solve(x + (n / 3), y + (n - (n / 3)), n / 3);
    solve(x + (n - (n / 3)), y + (n - (n / 3)), n / 3);
}
*/

void solve(int x, int y, int n)
{
    if (n == 1)
    {
        arr[y][x] = '*';
        return;
    }

    int nxt = n / 3;
    
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            // 가운데는 제외
            if (i == 1 && j == 1)
            {
                continue;
            }
            solve(x + (nxt * j), y + (nxt * i), nxt);
        }
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int n;
    cin >> n;

    memset(arr, ' ', sizeof(arr));
    solve(0, 0, n);

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cout << arr[i][j];
        }
        cout << "\n";
    }

    return 0;
}
