#include <iostream>
#include <string>
using namespace std;

int arr[65][65];

string solve(int x, int y, int n)
{
    // 1의 개수를 카운트
    int cnt = 0;

    for (int i = y; i < y + n; ++i)
    {
        for (int j = x; j < x + n; ++j)
        {
            if (arr[i][j] == 1)
            {
                cnt++;
            }
        }
    }

    string upperLeft;
    string upperRight;
    string lowerLeft;
    string lowerRight;

    if (cnt == n * n)
    {
        return "1";
    }
    else if (cnt == 0)
    {
        return "0";
    }
    else
    {
        upperLeft = solve(x, y, n / 2);
        upperRight = solve(x + (n / 2), y, n / 2);
        lowerLeft = solve(x, y + (n / 2), n / 2);
        lowerRight = solve(x + (n / 2), y + (n / 2), n / 2);
    }
    
    return "(" + upperLeft + upperRight + lowerLeft + lowerRight + ")";
}

int main()
{
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            scanf("%1d", &arr[i][j]);
        }
    }

    cout << solve(0, 0, n) << "\n";

    return 0;
}
