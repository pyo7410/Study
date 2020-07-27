#include <iostream>
#include <string>
using namespace std;

// �������� ����, �������� ��ȣ���� ����

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
            if (n / 2 < i) // ��������� (����Ʈ���̹Ƿ� �������� ��ü����� ���� n�� ��� n / 2 ���� ū ���� �����ϴ�.)
            {
                if (alpha == '+' || alpha == '-' || alpha == '*' || alpha == '/') // ���ڰ� �ƴ϶��
                {
                    ans = 0;
                    break;
                }
            }
            else // ������尡 �ƴ϶��
            {
                if (alpha >= '0' && alpha <= '9') // ��ȣ�� �ƴ϶��
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
