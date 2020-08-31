#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> weak, vector<int> dist)
{
    int answer = -1;
    vector<int> wall(201, 0);

    // 외벽의 취약 지점 표시
    for (int i = 0; i < weak.size(); ++i)
    {
        wall[weak[i]] = 1;
    }

    // 친구 순서를 정하기 위함
    vector<int> friends;
    for (int i = 0; i < dist.size(); ++i)
    {
        friends.push_back(i);
    }

    sort(friends.begin(), friends.end());

    // 각 취약위치마다 한번씩 시작을 해본다.
    for (int i = 0; i < weak.size(); ++i)
    {
        do
        {
            // 보낼 친구
            int idx = 0;
            // 보낸 친구의 수
            int friend_cnt = 0;
            // 취약지점부터 끝까지 전부 검사하고 마지막 취약지점인지 파악하기 위함
            int j;
            // 점검 여부를 파악하기 위한 벽
            vector<int> copy_wall = wall;

            // 취약지점부터 끝까지 전부 검사한다.
            for (j = 0; j < n; ++j)
            {
                int cur_idx = (weak[i] + j) % n;

                // 해당 부분이 취약지점이라면
                if (copy_wall[cur_idx] == 1)
                {
                    // 만약 친구를 다 보냈다면
                    if (idx == dist.size())
                    {
                        // 정지
                        break;
                    }

                    for (int k = 0; k <= dist[friends[idx]]; ++k)
                    {
                        // 취약 지점 점검 완료
                        int next_idx = (cur_idx + k) % n;
                        copy_wall[next_idx] = 0;
                    }

                    // 다음 친구 준비
                    idx += 1;

                    // 보낸 친구 +1
                    friend_cnt += 1;
                }
            }

            // 정상적으로 마지막까지 전부 탐색했다면
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
