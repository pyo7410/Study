#include <iostream>
#include <string>
#include <vector>
#define MAX 987654321
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    int board_size = board.size();

    // 해당하는 열의 top의 인덱스를 저장
    vector<int> top_idx(board_size, MAX);
    vector<int> basket;

    // 각 열의 top 인덱스를 구한다.
    for (int i = 0; i < board_size; ++i)
    {
        for (int j = 0; j < board_size; ++j)
        {
            if (board[j][i] != 0)
            {
                // 0이 아닌 지점 즉, 각 열의 맨 위의 인덱스를 저장
                top_idx[i] = j;
                break;
            }
        }
    }

    int moves_size = moves.size();
    for (int i = 0; i < moves_size; ++i)
    {
        // moves의 원소는 1부터 시작함을 주의
        int idx = moves[i] - 1;

        // 만약 바구니가 비어있다면
        if (basket.empty())
        {
            // 만약 board_size 보다 크거나 같다면 이미 해당 열의 인형을 다 뽑은것이므로 제외
            if (top_idx[idx] < board_size)
            {
                // moves를 하고나면 인형이 빠지므로 그래프상 남은 인형은 아래에 위치하기 때문에 +1을 해준다.
                basket.push_back(board[top_idx[idx]++][idx]);
            }
        }
        else
        {
            // 만약 board_size 보다 크거나 같다면 이미 해당 열의 인형을 다 뽑은것이므로 제외
            if (top_idx[idx] < board_size)
            {
                // 잡은 인형과 basket의 top위치의 인형이 같다면
                if (board[top_idx[idx]][idx] == basket.back())
                {
                    // 잡은 인형을 안넣고
                    // basket의 맨 마지막의 인형을 지우면 인형 두개가 지워지는 효과가 생긴다.
                    basket.erase(basket.end() - 1);

                    // 인형은 지울때마다 두개씩 없어진다!
                    answer += 2;
                    top_idx[idx]++;
                }
                else
                {
                    basket.push_back(board[top_idx[idx]++][idx]);
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

    int n, m;
    cin >> n >> m;

    vector<vector<int>> board(n, vector<int>(n));

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> board[i][j];
        }
    }

    vector<int> moves(m);
    for (int i = 0; i < m; ++i)
    {
        cin >> moves[i];
    }

    cout << solution(board, moves) << endl;
    
    return 0;
}
