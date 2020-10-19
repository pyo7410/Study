#include <iostream>
using namespace std;

int solution(int n, int a, int b)
{
    int answer = 1;

    while (a != b)
    {
        if (a % 2 == 0)
        {
            a /= 2;
        }
        else
        {
            a = (a + 1) / 2;
        }

        if (b % 2 == 0)
        {
            b /= 2;
        }
        else
        {
            b = (b + 1) / 2;
        }

        if (a == b)
        {
            break;
        }

        answer++;
    }

    return answer;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, a, b;
    cin >> n >> a >> b;

    cout << solution(n, a, b) << "\n";

    return 0;
}