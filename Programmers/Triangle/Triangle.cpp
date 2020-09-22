#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 삼각형의 합을 저장한다.
int d[501][501];

int solution(vector<vector<int>> triangle) 
{
    int answer = 0;

    answer = triangle[0][0];
    d[0][0] = triangle[0][0];

    // 초기값을 설정 했으므로 1부터 시작
    for (int i = 1; i < triangle.size(); ++i)
    {
        // 해당 행을 모두 조사해야하므로 0부터 시작
        for (int j = 0; j < triangle[i].size(); ++j)
        {
            if (j == 0) // 맨 왼쪽이라면
            {
                // 오른쪽 위에 있는 값밖에 못받는다.
                d[i][j] = d[i - 1][j] + triangle[i][j];
            }
            else if (j == i) // 삼각형이므로 i == j 일 경우 해당 행의 맨 끝이된다.
            {
                // 왼쪽 위에 있는 값밖에 못받는다.
                d[i][j] = d[i - 1][j - 1] + triangle[i][j];
            }
            else
            {
                // 왼쪽위의 값고 오른쪽 위의 값중 큰 값을 받는다.
                d[i][j] = max(d[i - 1][j], d[i - 1][j - 1]) + triangle[i][j];
            }

            // 계산한 값과 현재 저장된 값중 큰 값을 저장한다.
            answer = max(d[i][j], answer);
        }
    }

    return answer;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    return 0;
}