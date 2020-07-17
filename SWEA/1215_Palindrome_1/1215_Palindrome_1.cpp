#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

string arr[8];

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
        int len;

        cin >> len;
        for (int i = 0; i < 8; ++i)
        {
            cin >> arr[i];
        }

        int ans = 0;
        
        // 가로
        for (int i = 0; i < 8; ++i)
        {
            for (int j = 0; j <= 8 - len; ++j)
            {
                int left = j;
                int right = len + j - 1;

                if (palindrome(left, right, i, 'r'))
                {
                    ans += 1;
                }
            }
        }

        // 세로
        for (int i = 0; i < 8; ++i)
        {
            for (int j = 0; j <= 8 - len; ++j)
            {
                int left = j;
                int right = len + j - 1;

                if (palindrome(left, right, i, 'c'))
                {
                    ans += 1;
                }
            }
        }

        cout << "#" << test_case << " " << ans << "\n";
    }    
    
    return 0;
}
