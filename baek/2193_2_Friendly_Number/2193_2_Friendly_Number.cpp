#include <iostream>
using namespace std;

// �� �ڸ��� ���� 0�� 1�� �����Ƿ�
long long dp[91][2];

long long solve(int n, int num)
{
    if (n == 1)
    {
        // �� �ڸ��϶�
        if (num == 0)
        {
            // ù ������ 0�̶��
            // 0 �� ����
            return 0;
        }
        else
        {
            // ù ������ 1�̶��
            // ��ģ���̹Ƿ� 1�� ����
            return 1;
        }
    }

    if (dp[n][num] > 0)
    {
        return dp[n][num];
    }

    if (num == 0)
    {
        dp[n][num] = solve(n - 1, 0) + solve(n - 1, 1);
    }
    else if (num == 1)
    {
        dp[n][num] = solve(n - 1, 0);
    }

    return dp[n][num];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int n;
    cin >> n;

    long long result = 0;
    for (int i = 0; i < 2; ++i)
    {
        result += solve(n, i);
    }

    cout << result << "\n";

    return 0;
}
