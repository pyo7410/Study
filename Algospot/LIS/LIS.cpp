#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
int arr[501];
int dp[501];

int solve(int start)
{
    // �̹� ���� ���̶��
    if (dp[start] != -1)
    {
        return dp[start];
    }

    // ������ �������� �����ϹǷ�
    dp[start] = 1;

    for (int i = start + 1; i < n; ++i)
    {
        if (arr[start] < arr[i])
        {
            // Ƚ ���� ���ϴ� �����̹Ƿ� solve(i)�� ������� ���� ��ġ�� ���ϱ� ���� + 1�� ���ָ� �ȴ�.
            dp[start] = max(dp[start], solve(i) + 1);
        }
    }

    return dp[start];
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
        memset(arr, 0, sizeof(arr));
        cin >> n;

        for (int i = 0; i < n; ++i)
        {
            cin >> arr[i];
        }

        // �� �ε������� �� �� LIS�� ������ �� �����Ƿ�
        int maxLen = 0;
        for (int i = 0; i < n; ++i)
        {
            maxLen = max(maxLen, solve(i));
        }

        cout << maxLen << "\n";
    }

    return 0;
}
