#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// https://yabmoons.tistory.com/552

int solution(int n, vector<int> weak, vector<int> dist) {
    int answer = -1;

    sort(dist.begin(), dist.end());

    // ��� ��� ������ ���� ����
    for (int i = 0; i < weak.size(); ++i)
    {
        do {
            int weak_idx = 0;
            int dist_idx = 0;

            // ģ���� �� �� �ִ� ��������� ��� Ž��
            for (dist_idx = 0; dist_idx < dist.size(); ++dist_idx)
            {
                int finish_idx = weak[weak_idx] + dist[dist_idx];

                while (finish_idx >= weak[weak_idx])
                {
                    weak_idx += 1;
                    if (weak_idx == weak.size())
                    {
                        break;
                    }
                }

                if (weak_idx == weak.size())
                {
                    break;
                }
            }

            if (weak_idx == weak.size())
            {
                // dist_idx�� 0���� ���������Ƿ�
                if (answer == -1 || dist_idx + 1 < answer) 
                {
                    answer = dist_idx + 1;
                }
            }

        } while (next_permutation(dist.begin(), dist.end()));

        // ��� ���� ��ȯ
        int temp = weak[0] + n;
        for (int j = 1; j < weak.size(); ++j)
        {
            weak[j - 1] = weak[j];
        }
        weak[weak.size() - 1] = temp;
    }

    return answer;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int n;
    cin >> n;

    int a, b;
    cin >> a >> b;

    vector<int> weak(a);
    vector<int> dist(b);

    for (int i = 0; i < a; ++i)
    {
        cin >> weak[i];
    }
    for (int i = 0; i < b; ++i)
    {
        cin >> dist[i];
    }

    cout << solution(n, weak, dist) << endl;
    
    return 0;
}
