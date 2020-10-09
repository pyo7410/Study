#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> solution(int n) {
    vector<int> answer;

    vector<vector<int>> triangle(n, vector<int>(n, 0));

    int num = 1;
    int N = n;

    // 0 : 아래, 1 : 오른쪽, 2 : 위
    int dir = 0;

    int ii = 0, jj = 0;
    
    while (n > 0)
    {
        // 아래로 내려가는 방향
        if (dir == 0)
        {
            for (int i = 0; i < n; ++i)
            {
                triangle[ii++][jj] = num++;
            }

            // 아래쪽 방향 다음은 순서에 의해 오른쪽 방향이 된다.
            // 아래쪽으로 내려갔으니 오른쪽 방향의 시작 지점으로 옮김
            dir = 1;
            jj++;
            ii--;
            // n을 1 줄여주어 다음 방향의 횟수를 정해준다.
            n--;
        }
        else if (dir == 1) // 오른쪽 방향
        {
            for (int i = 0; i < n; ++i)
            {
                triangle[ii][jj++] = num++;
            }

            // 오른쪽 방향 다음은 순서에 의해 위쪽 방향이 된다.
            // 오른쪽으로 갔으니 위쪽 방향의 시작 지점으로 옮김
            dir = 2;
            ii--;
            jj -= 2;

            // n을 1 줄여주어 다음 방향의 횟수를 정해준다.
            n--;
        }
        else if (dir == 2)
        {
            for (int i = 0; i < n; ++i)
            {
                triangle[ii--][jj--] = num++;
            }

            // 위쪽 방향 다음은 순서에 의해 아래 방향이 된다.
            // 위쪽 방향으로 올라갔으니 아래쪽 방향의 시작 지점으로 옮김
            dir = 0;
            ii += 2;
            jj++;
            // n을 1 줄여주어 다음 방향의 횟수를 정해준다.
            n--;
        }
    }

    for (int i = 0; i < N; ++i)
    {
        if (triangle[i][0] == 0)
        {
            break;
        }

        for (int j = 0; j < N; ++j)
        {
            if (triangle[i][j] == 0)
            {
                break;
            }

            if (triangle[i][j] != 0)
            {
                answer.push_back(triangle[i][j]);
            }
        }
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

    vector<int> ans = solution(n);

    for (int i = 0; i < ans.size(); ++i)
    {
        cout << ans[i] << ", ";
    }

    return 0;
}