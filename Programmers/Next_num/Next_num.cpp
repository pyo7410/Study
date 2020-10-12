#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

int solution(int n) {
    int answer = 0;

    string binary = "";

    while (n > 0)
    {
        binary = to_string(n % 2) + binary;
        n /= 2;
    }

    // 0을 하나 더 추가시켜 전부 1일 경우나
    // 전부 0일 경우 다음 큰 수를 구할 수 있게 해준다.
    binary = "0" + binary;

    next_permutation(binary.begin(), binary.end());

    // for문 밖에 len을 빼는 것으로 시간초과를 피할 수도 있다.
    int len = binary.length();
    for (int i = len - 1; i >= 0; i--)
    {
        if (binary[i] == '1')
        {
            // 2^0 부터 표현하기 위해 -1을 해준다.
            answer += pow(2, len - i - 1);
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

    cout << solution(n);

    return 0;
}