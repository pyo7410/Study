#include <iostream>
using namespace std;

string pw[10] = {"0001101", "0011001", "0010011", "0111101", "0100011", "0110001", "0101111", "0111011", "0110111", "0001011"};
string arr[50];
int n, m;

string find_code()
{
    string s = "";

    for (int i = 0; i < n; ++i)
    {
        int end = arr[i].rfind("1");

        if (end != -1)
        {
            s.assign(arr[i], end - 55, 56);
            break;
        }
    }

    return s;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int tc;
    cin >> tc;
    for (int test_case = 1; test_case <= tc; ++test_case)
    {
        cin >> n >> m;

        for (int i = 0; i < n; ++i)
        {
            cin >> arr[i];
        }

        string code = find_code();
        string code_num;

        int odd = 0;
        int even = 0;
        
        // string 에선 0이 첫번째 코드이지만 문제에선 첫번째 코드가 1이 된다.
        // 즉 여기선 even과 odd가 바뀐다.
        if (!code.empty())
        {
            for (int i = 0; i < 8; ++i)
            {
                code_num.assign(code, i * 7, 7);
                for (int j = 0; j < 10; ++j)
                {
                    if (code_num == pw[j])
                    {
                        if (i % 2 == 0)
                        {
                            odd += j;
                        }
                        else
                        {
                            even += j;
                        }

                        break;
                    }
                }
            }
        }

        if ((even + (odd * 3)) % 10 == 0)
        {
            cout << "#" << test_case << " " << even + odd << "\n";
        }
        else
        {
            cout << "#" << test_case << " " << 0 << "\n";
        }
        
    }

    return 0;
}
