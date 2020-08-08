#include <iostream>
#include <algorithm>
using namespace std;

double dp[10001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cout << fixed;
    cout.precision(3);

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        cin >> dp[i];
    }

    double answer = -1;
    for (int i = 1; i < n; ++i)
    {
        // ���������� ���� ������ ���� ���Ͽ� ���� �ִ밡 �Ǵ� �κ��� �� �� �ִ�.
        dp[i] = max(dp[i], dp[i] * dp[i - 1]);
        answer = max(dp[i], answer);
    }

    cout << answer << "\n";
    
    return 0;
}
