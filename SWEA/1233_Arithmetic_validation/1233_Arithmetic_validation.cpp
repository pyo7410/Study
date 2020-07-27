#include <iostream>
#include <string>
using namespace std;

// 리프노드는 숫자, 나머지는 기호임을 주의

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    for (int test_case = 1; test_case <= 10; ++test_case)
    {
        string tree[201];
        int degree[201];

        int n;
        cin >> n;

        int num, child_node;
        string alphabet;

        for (int i = 1; i <= n; ++i)
        {
            int cnt = 0;

            cin >> num >> alphabet;

            if (num * 2 <= n) 
            {
                cin >> child_node;
                cnt += 1;
            }    
            if (num * 2 < n)
            {
                cin >> child_node;
                cnt += 1;
            }

            degree[num] = cnt;
            tree[num] = alphabet;
        }

        int ans = 1;

        for (int i = 1; i <= n; ++i)
        {
            char alpha = tree[i][0];
            if (n / 2 < i) // 리프노드라면 (이진트리이므로 리프노드는 전체노드의 수가 n일 경우 n / 2 보다 큰 수만 가능하다.)
            {
                if (alpha == '+' || alpha == '-' || alpha == '*' || alpha == '/') // 숫자가 아니라면
                {
                    ans = 0;
                    break;
                }
            }
            else // 리프노드가 아니라면
            {
                if (alpha >= '0' && alpha <= '9') // 기호가 아니라면
                {
                    ans = 0;
                    break;
                }
            }            
        }

        cout << "#" << test_case << " " << ans << "\n";    
    }
    
    return 0;
}
