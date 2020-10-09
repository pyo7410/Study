#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int dp[1001][1001];

/*
int solve(int x, int y, vector<vector<int>> board)
{
    if (x < 0 || y < 0)
    {
        return 0;
    }

    if (board[y][x] == 0)
    {
        return 0;
    }

    if (dp[y][x] != -1)
    {
        return dp[y][x];
    }

    // 가장 큰 정사각형을 구하기 위해서는
    // DP를 사용하여 현재 점부터 사각형을 이루는 점들을 조사해서
    // 가장 짧은 길이가 정사각형의 변의 길이가 된다.
    dp[y][x] = min({solve(x - 1, y, board), solve(x, y - 1, board), solve(x - 1, y - 1, board)}) + 1;

    return dp[y][x];
}
*/

int solution(vector<vector<int>> board)
{
    memset(dp, 0, sizeof(dp));
    int answer = 0;

    int height = board.size();
    int width = board[0].size();

    for (int i = 1; i <= height; ++i)
    {
        for (int j = 1; j <= width; ++j)
        {
            // 1인지 0인지 파악하기 위해 마지막에 board[i - 1][j - 1] 값 을 곱해준다.
            dp[i][j] = (min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1) * board[i - 1][j - 1];

            answer = max(answer, dp[i][j]);
        }
    }
    
    return answer * answer;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> board(n, vector<int>(m));

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> board[i][j];
        }
    }

    cout << solution(board) << "\n";

    return 0;
}