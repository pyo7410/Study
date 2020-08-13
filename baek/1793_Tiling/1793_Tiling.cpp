#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string dp[251];

string bigInteger(string s1, string s2)
{
    long long sum = 0;
    string result;

    // 1의 자리부터 더함
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

        // char 형태로 만들어 result에 push_back
        // 뒤의 숫자부터 즉, 1의 자리부터 result의 앞에 쌓인다.
        result.push_back((sum % 10) + '0');
        sum /= 10;
    }

    // 1의 자리부터 넣었기 때문에 reverse해야 구하고자 하는 수가 된다.
    reverse(result.begin(), result.end());
    return result;
}

int main()
{
    int n;

    // 미리 구해둔다.
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
