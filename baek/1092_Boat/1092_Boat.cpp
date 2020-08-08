#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> n;
    vector<int> crane(n);
    for(int i = 0; i < n; ++i)
    {
        cin >> crane[i];
    }

    cin >> m;
    vector<int> weight(m);
    for (int i = 0; i < m; ++i)
    {
        cin >> weight[i];
    }

    // 그리디 이므로 높은것 먼저 뽑도록 했다.
    sort(crane.begin(), crane.end(), greater<int>());
    sort(weight.begin(), weight.end(), greater<int>());

    if (crane[0] < weight[0])
    {
        cout << -1 << "\n";
    }
    else
    {
        int count = 0;
        while (!weight.empty())
        {
            int crane_idx = 0;
            for (int i = 0; i < weight.size(); ++i)
            {
                if (crane_idx == crane.size())
                {
                    break;
                }

                if (crane[crane_idx] >= weight[i])
                {
                    crane_idx += 1;
                    weight.erase(weight.begin() + i);
                    // erase로 원소를 지우면 뒤에있는 원소들이 빈 공간을 채운다.
                    // 그러므로 i를 -1을 해주어야 지운원소 뒤에부터 다시 시작이 가능하다.
                    i -= 1;  
                }
            }
            count += 1;
        }
        cout << count << "\n";
    }
    
    return 0;
}
