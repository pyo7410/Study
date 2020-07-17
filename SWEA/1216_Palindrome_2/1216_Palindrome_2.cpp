#include <iostream>
#include <string>
using namespace std;

string arr[100];

bool palindrome(int l, int r, int idx, char r_c)
{
    if (r_c == 'r')
    {
        while (l < r)
        {
            if (arr[idx][l] != arr[idx][r])
            {
                return false;
            }

            l += 1;
            r -= 1;
        }
    }
    else if (r_c == 'c')
    {
        while (l < r)
        {
            if (arr[l][idx] != arr[r][idx])
            {
                return false;
            }

            l += 1;
            r -= 1;
        }
    }

    return true;    
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    for (int test_case = 1; test_case <= 10; ++test_case)
    {
        int n;
        cin >> n;

        for (int i = 0; i < 100; ++i)
        {
            cin >> arr[i];
        }

        int ans = 0;
        
        // 가로
        bool isPalin = false;
        for (int i = 0; i < 100; ++i)
        {
            for (int j = 0; j < 100; ++j)
            {
                for (int len = 99; len > j; len--)
                {
                    if (palindrome(j, len, i, 'r'))
                    {
                        isPalin = true;
                        if (ans < (len - j + 1))
                        {
                            ans = len - j + 1;
                        }
                    }
                }
            }
        }
        
        // 행 또는 열 별로 회문의 최대 길이가 바뀔 수 있음을 주의

        // 세로
        isPalin = false;
        for (int i = 0; i < 100; ++i)
        {
            for (int j = 0; j < 100; ++j)
            {
                for (int len = 99; len > j; len--)
                {
                    if (palindrome(j, len, i, 'c'))
                    {
                        isPalin = true;
                        if (ans < (len - j + 1))
                        {
                            ans = len - j + 1;
                        }
                    }
                }
            }
        }

        cout << "#" << test_case << " " << ans << "\n";
    }
    
    return 0;
}
