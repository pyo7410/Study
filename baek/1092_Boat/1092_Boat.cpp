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

    // �׸��� �̹Ƿ� ������ ���� �̵��� �ߴ�.
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
                    // erase�� ���Ҹ� ����� �ڿ��ִ� ���ҵ��� �� ������ ä���.
                    // �׷��Ƿ� i�� -1�� ���־�� ������� �ڿ����� �ٽ� ������ �����ϴ�.
                    i -= 1;  
                }
            }
            count += 1;
        }
        cout << count << "\n";
    }
    
    return 0;
}
