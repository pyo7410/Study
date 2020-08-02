#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
    
    FILE* fp = freopen("C:\\Users\\pyo74\\Desktop\\git-project\\Study\\SWEA\\input_output\\1244_input.txt", "r", stdin);

    int tc;
    cin >> tc;

    for (int test_case = 1; test_case <= 10; ++test_case)
    {
        string num;
        int cnt;
        cin >> num >> cnt;

        int max_num = -1;
        int len = num.length();
        int swap_cnt = 0;

        for (int j = 0; j < len - 1; ++j)
        {
            if (swap_cnt == cnt)
            {
                break;
            }
            
            int max_idx = -1;
            for (int k = j + 1; k < len; ++k)
            {
                if (num[j] <= num[k])
                {
                    string temp = num;
                    swap(temp[j], temp[k]);

                    if (max_num <= stoi(temp))
                    {
                        max_num = stoi(temp);
                        max_idx = k;
                    }
                }
            }

            if (max_idx > -1)
            {
                swap(num[j], num[max_idx]);
                swap_cnt += 1;
            }
        }

        cout << "#" << test_case << " " << num << "\n";
    }
    
    return 0;
}
