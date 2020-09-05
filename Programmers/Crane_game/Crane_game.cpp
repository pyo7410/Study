#include <iostream>
#include <string>
#include <vector>
#define MAX 987654321
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    int board_size = board.size();

    // �ش��ϴ� ���� top�� �ε����� ����
    vector<int> top_idx(board_size, MAX);
    vector<int> basket;

    // �� ���� top �ε����� ���Ѵ�.
    for (int i = 0; i < board_size; ++i)
    {
        for (int j = 0; j < board_size; ++j)
        {
            if (board[j][i] != 0)
            {
                // 0�� �ƴ� ���� ��, �� ���� �� ���� �ε����� ����
                top_idx[i] = j;
                break;
            }
        }
    }

    int moves_size = moves.size();
    for (int i = 0; i < moves_size; ++i)
    {
        // moves�� ���Ҵ� 1���� �������� ����
        int idx = moves[i] - 1;

        // ���� �ٱ��ϰ� ����ִٸ�
        if (basket.empty())
        {
            // ���� board_size ���� ũ�ų� ���ٸ� �̹� �ش� ���� ������ �� �������̹Ƿ� ����
            if (top_idx[idx] < board_size)
            {
                // moves�� �ϰ��� ������ �����Ƿ� �׷����� ���� ������ �Ʒ��� ��ġ�ϱ� ������ +1�� ���ش�.
                basket.push_back(board[top_idx[idx]++][idx]);
            }
        }
        else
        {
            // ���� board_size ���� ũ�ų� ���ٸ� �̹� �ش� ���� ������ �� �������̹Ƿ� ����
            if (top_idx[idx] < board_size)
            {
                // ���� ������ basket�� top��ġ�� ������ ���ٸ�
                if (board[top_idx[idx]][idx] == basket.back())
                {
                    // ���� ������ �ȳְ�
                    // basket�� �� �������� ������ ����� ���� �ΰ��� �������� ȿ���� �����.
                    basket.erase(basket.end() - 1);

                    // ������ ���ﶧ���� �ΰ��� ��������!
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
