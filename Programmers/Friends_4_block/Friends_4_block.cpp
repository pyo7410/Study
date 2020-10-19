#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isSame(int i, int j, vector<string> board)
{
    // 4칸이 모두 같다면
    if ((board[i][j] == board[i][j + 1]) && (board[i][j] == board[i + 1][j])
        && (board[i][j] == board[i + 1][j + 1])) {
            return true;
        }

    return false;
}

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    bool check = false;

    while (!check)
    {
        vector<vector<bool>> visit(m, vector<bool>(n));
        check = true;

        // i를 기준으로 오른쪽, 아래, 오른쪽아래 검사하므로
        // m - 1, n - 1 까지 반복
        for (int i = 0; i < m - 1; ++i)
        {
            for (int j = 0; j < n - 1; ++j)
            {
                // 지운 공간은 0으로 만들으므로
                // 검사를 하지 않아도 된다.
                if (board[i][j] != '0')
                {
                    if (isSame(i, j, board))
                    {
                        visit[i][j] = true;
                        visit[i][j + 1] = true;
                        visit[i + 1][j] = true;
                        visit[i + 1][j + 1] = true;
                        check = false;
                    } 
                }
            }
        }

        // visit가 true로 되있는 칸을 지운다.
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                // 지워야할 대상이라면
                if (visit[i][j] == 1)
                {
                    // 지운 횟수 +1
                    answer++;

                    // 모든점을 기준으로 검사하므로
                    // 마지막에는 전부 지워지게 되어있다.
                    for (int k = i - 1; k >= 0; k--)
                    {
                        board[k + 1][j] = board[k][j];
                        board[k][j] = '0';
                    }
                }
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

    int m, n;
    cin >> m >> n;
    vector<string> board(m);

    for (int i = 0; i < m; ++i)
    {
        cin >> board[i];
    }

    cout << solution(m, n, board) << "\n";

    return 0;
}