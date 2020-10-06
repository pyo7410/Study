#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
int triangle[101][101];
int dp[101][101];

int solve(int x, int y)
{
    // �� �Ʒ����
    if (y == n - 1)
    {
        return triangle[y][x];
    }

    // ������ ����ߴ� ������� ����ִٸ�
    if (dp[y][x] != -1)
    {
        // ���� ������� ����
        return dp[y][x];
    }

    // �ٷ� �Ʒ� �ƴϸ� �Ʒ����� �� ĭ �������� �����Ѵ�.
    dp[y][x] = max(solve(x, y + 1), solve(x + 1, y + 1)) + triangle[y][x];

    return dp[y][x];
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int c;
    cin >> c;

    while (c--)
    {
        memset(dp, -1, sizeof(dp));
        memset(triangle, 0, sizeof(triangle));

        cin >> n;

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j <= i; ++j)
            {
                cin >> triangle[i][j];
            }
        }

        cout << solve(0, 0) << "\n";
    }

    return 0;
}
