#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int k;

    while (true)
    {
        cin >> k;

        if (k == 0)
        {
            break;
        }

        vector<int> s(k);
        vector<int> d; // �� ���� : 1, �� �� ���� : 0 ���� ������ �̿�
        vector<vector<int>> ans; // ����� ������ ����

        for (int i = 0; i < k; ++i)
        {
            cin >> s[i];
        }

        for (int i = 0; i < k - 6; ++i) // 6���� �� ���̹Ƿ� �������� �Ȱ�
        {
            d.push_back(0);
        }

        for (int i = 0; i < 6; ++i)
        {
            d.push_back(1);
        }

        do 
        {
            vector<int> vec;

            for (int i = 0; i < k; ++i)
            {
                if (d[i] == 1)
                {
                    vec.push_back(s[i]);
                }
            }

            ans.push_back(vec);
        } while (next_permutation(d.begin(), d.end()));

        sort(ans.begin(), ans.end());
        
        for (int i = 0; i < ans.size(); ++i)
        {
            for (int j = 0; j < ans[i].size(); ++j)
            {
                cout << ans[i][j] << " ";
            }
            cout << "\n";
        }

        /*
        for (auto &v : ans)
        {
            for (int i = 0; i < v.size(); ++i)
            {
                cout << v[i] << " ";
            }
            cout << "\n";
        }
        */
       
        cout << "\n";
    }
}
