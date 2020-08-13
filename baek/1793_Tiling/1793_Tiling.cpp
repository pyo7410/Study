#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string dp[251];

string bigInteger(string s1, string s2)
{
    long long sum = 0;
    string result;

    // 1�� �ڸ����� ����
    while (!s1.empty() || !s2.empty() || sum)
    {
        if (!s1.empty())
        {
            sum += s1.back() - '0';
            s1.pop_back();
        }
        if (!s2.empty())
        {
            sum += s2.back() - '0';
            s2.pop_back();
        }

        // char ���·� ����� result�� push_back
        // ���� ���ں��� ��, 1�� �ڸ����� result�� �տ� ���δ�.
        result.push_back((sum % 10) + '0');
        sum /= 10;
    }

    // 1�� �ڸ����� �־��� ������ reverse�ؾ� ���ϰ��� �ϴ� ���� �ȴ�.
    reverse(result.begin(), result.end());
    return result;
}

int main()
{
    int n;

    // �̸� ���صд�.
    dp[0] = '1';
    dp[1] = '1';
    for (int i = 2; i <= 250; ++i)
    {
        dp[i] = bigInteger(bigInteger(dp[i - 2], dp[i - 2]), dp[i - 1]);
    }

    while (~scanf("%d", &n))
    {
        cout << dp[n] << "\n";
    }    
    return 0;
}
