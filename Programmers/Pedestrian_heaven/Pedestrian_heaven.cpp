#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

// 오른쪽으로 갈 수 있는 경우의 수
int right_dir[501][501];
// 아래쪽으로 갈 수 있는 경우의 수
int down_dir[501][501];

int MOD = 20170805;  // 나머지 연산에 쓰이는 수

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int m, int n, vector<vector<int>> city_map) {
    int answer = 0;

    memset(right_dir, 0, sizeof(right_dir));
    memset(down_dir, 0, sizeof(down_dir));
    
    // 1부터 시작함을 주의
    // 첫 위치에서는 오른쪽이랑 아래 둘다 갈 수 있다.
    // 만약 0, 0 에서 시작할 경우 0, 1에서 아래 방향의 가지수를 구할떄
    // -1, 1 이 되버리므로 이를 방지하고자 1, 1부터 시작
    right_dir[1][1] = 1;
    down_dir[1][1] = 1;

    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (city_map[i - 1][j - 1] == 0)
            {
                // 왼쪽이나 위쪽에서 오는 경우를 더하면 된다.
                right_dir[i][j] += (right_dir[i][j - 1] + down_dir[i - 1][j]) % MOD;
                down_dir[i][j] += (right_dir[i][j - 1] + down_dir[i - 1][j]) % MOD;
            }
            else if (city_map[i - 1][j - 1] == 2)
            {
                // 이 경우 오른쪽은 왼쪽에서 들어오는 방향만
                right_dir[i][j] = right_dir[i][j - 1];
                // 아래쪽은 위에서 들어오는 방향만 가능하다.
                down_dir[i][j] = down_dir[i - 1][j];
            }
            else if (city_map[i - 1][j - 1] == 1)
            {
                // 막혀 있어 갈 수가 없으므로 0
                right_dir[i][j] = 0;
                down_dir[i][j] = 0;
            }
        }
    }

    answer = down_dir[m][n] % MOD;
    return answer;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> city_map(n, vector<int>(m));

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> city_map[i][j];
        }
    }

    cout << solution(m, n, city_map) << "\n";

    return 0;
}