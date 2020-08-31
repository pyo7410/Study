#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> weak, vector<int> dist)
{
    int answer = -1;
    vector<int> wall(201, 0);

    // �ܺ��� ��� ���� ǥ��
    for (int i = 0; i < weak.size(); ++i)
    {
        wall[weak[i]] = 1;
    }

    // ģ�� ������ ���ϱ� ����
    vector<int> friends;
    for (int i = 0; i < dist.size(); ++i)
    {
        friends.push_back(i);
    }

    sort(friends.begin(), friends.end());

    // �� �����ġ���� �ѹ��� ������ �غ���.
    for (int i = 0; i < weak.size(); ++i)
    {
        do
        {
            // ���� ģ��
            int idx = 0;
            // ���� ģ���� ��
            int friend_cnt = 0;
            // ����������� ������ ���� �˻��ϰ� ������ ����������� �ľ��ϱ� ����
            int j;
            // ���� ���θ� �ľ��ϱ� ���� ��
            vector<int> copy_wall = wall;

            // ����������� ������ ���� �˻��Ѵ�.
            for (j = 0; j < n; ++j)
            {
                int cur_idx = (weak[i] + j) % n;

                // �ش� �κ��� ��������̶��
                if (copy_wall[cur_idx] == 1)
                {
                    // ���� ģ���� �� ���´ٸ�
                    if (idx == dist.size())
                    {
                        // ����
                        break;
                    }

                    for (int k = 0; k <= dist[friends[idx]]; ++k)
                    {
                        // ��� ���� ���� �Ϸ�
                        int next_idx = (cur_idx + k) % n;
                        copy_wall[next_idx] = 0;
                    }

                    // ���� ģ�� �غ�
                    idx += 1;

                    // ���� ģ�� +1
                    friend_cnt += 1;
                }
            }

            // ���������� ���������� ���� Ž���ߴٸ�
            if (j == n)
            {
                if (answer == -1 || friend_cnt < answer)
                {
                    answer = friend_cnt;
                }
            }

        } while (next_permutation(friends.begin(), friends.end()));
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
