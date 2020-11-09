#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k;
    cin >> n >> k;

    int answer = 0;

    // n이 k의 배수가 될 때 까지 1을 만들어주면 k로 나눌 경우 최소가 되므로
    while (1)
    {
        // k로 나눌 수 있는 현재의 가장 큰 수를 구한다.
        int temp = (n / k) * k;

        // k로 나누어지는 수로 만들기위한 -1의 수
        answer += (n - temp);

        n = temp;

        // n이 k보다 작다면 k로 나눌 수 없으므로
        if (n < k)
        {
            break;
        }

        answer++;
        n /= k;
    }

    // 남은 수는 k로 나눌 수 없으므로 1을 제외한 n - 1을 더해준다.
    answer += (n - 1);

    cout << answer << "\n";

    return 0;
}