#include <iostream>
#include <string>
#include <vector>
using namespace std;

int solution(int n) 
{
    // n 자기자신도 포함시켜야 하므로
    // 초기값은 1이 된다.
    int answer = 1;

    // 자연수는 1부터 이므로
    // n / 2 보다 큰 값끼리 더하면 무조건 n보다 커지게 되므로
    // 반복문은 n / 2 까지만 하면된다.
    for (int i = 1; i <= n / 2; ++i)
    {
        int sum = i;
        // i 는 n / 2까지 이므로 덧셈을 위해서는 n / 2 + 1 까지 반복해주어야 한다.
        for (int j = i + 1; j <= n / 2 + 1; ++j)
        {
            sum += j;

            if (sum == n)
            {
                answer++;
                break;
            }
            else if (sum > n)
            {
                break;
            }
        }
    }

    return answer;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    cout << solution(n) << "\n";

    return 0;
}