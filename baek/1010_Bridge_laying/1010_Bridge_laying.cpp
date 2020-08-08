#include <iostream>
#include <cstring>
using namespace std;

long long dp[31][31];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        // �Ź� ���� 0���� �ʱ�ȭ ��������!
        memset(dp, 0, sizeof(dp));
        int n, m;
        cin >> n >> m;

        // �ٸ� 1���� m�� ����Ʈ�� ������ �������� m���� �ȴ�
        for (int i = 1; i <= m; ++i)
        {
            dp[1][i] = i;
        }

        for (int i = 2; i <= n; ++i)
        {
            // �ٸ��� ��ġ�� �ȵǹǷ� i �Ʒ��θ� ���ο� �ٸ��� ���� �� �ִ�!
            for (int j = i; j <= m; ++j)
            {
                // i �Ʒ��� �������� �ٸ��� ��! ��! i�� ���� �� ���ٴ� �Ϳ� ����
                for (int k = j; k >= i; k--)
                {
                    dp[i][j] += dp[i - 1][k - 1];
                }
            }
        }

        cout << dp[n][m] << "\n";
    }
    
    return 0;
}
