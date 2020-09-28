#include <iostream>
#include <string>
using namespace std;

int solution(string s)
{
    int len = s.length();

    // len을 1/2 씩 줄이며 검사
    while (len >= 2)
    {
        // 펠린드롬은 가운데를 기점으로 뒤집어도 똑같은 문자이므로
        // len을 빼서 0, 1, 2 글자씩 점점 늘려간다.
        for (int i = 0; i <= s.length() - len; ++i)
        {
            // 가장 왼쪽 값
            int left = i;
            // 가장 오른쪽 값
            int right = len + i - 1;
            bool check = true;

            while (left < right)
            {
                if (s[left] != s[right])
                {
                    check = false;
                    break;
                }

                left++;
                right--;
            }

            if (check)
            {
                return len;
            }
        }
        len--;
    }

    return 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s;
    cin >> s;

    cout << solution(s) << "\n";

    return 0;
}