#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//����� �ٴ� ���� �ְų� ���� ���� �� �κ� ���� �ְų�,
//�Ǵ� �ٸ� ��� ���� �־�� �մϴ�.

//���� ���� �� �κ��� ��� ���� �ְų�,
//�Ǵ� ���� �� �κ��� �ٸ� ���� ���ÿ� ����Ǿ� �־�� �մϴ�.


// x, y�� �ε����� �ƴ� x�� y���� ��ǥ�� �����Ѵ�.
// n�� 5 ~ 100 ������ �ڿ���
// type -> 0 : ���, 1 : ��
// ���� ������ �����Ѵ�.
bool board[101][101][2]; // x, y, type
int boardSize;

bool check(int x, int y) {
    if(x < 0 || y < 0 || x > boardSize || y > boardSize) {
        return false;
    }
    return true;
}

// �� ����
bool isBuilt(int x, int y, int type)
{
    if (type) // �� �϶�
    {
        // ���� �� �κ��� ��� ���ų�
        // ���� ���������� ��ġ ���� ����
        if((check(x, y - 1) && board[x][y - 1][0]) || (check(x + 1, y - 1) && board[x + 1][y - 1][0]))
        {
            return true;
        }

        // ���� �� �κ��� �ٸ� ���� ������ִٸ�
        // x - 1���� �����ϴ� ���� x + 1���� �����ϴ� ��
        if((check(x - 1, y) && check(x + 1, y)) && board[x - 1][y][1] && board[x + 1][y][1])
        {
            return true;
        }
    }
    else // ��� �϶�
    {
        // �ٴ��̰ų�
        if (y == 0)
        {
            return true;
        }

        // ���� ���� �� �κ� ���� �ְų�
        // ���� ���� �� �κ��̳�, ������ ���� ���� �κ��̳�
        // ���� ���������� ��ġ ���� ����
        if((check(x - 1, y) && board[x - 1][y][1]) || board[x][y][1])
        {
            return true;
        }

        // �ٸ� ��������
        if(check(x, y - 1) && board[x][y - 1][0])
        {
            return true;
        }
    }

    return false;
}

// ��� ����
// �̸� ��հ� ���� �����
bool isRemove()
{
    // ��� ���� ��տ� ���ؼ� �����Ͽ�
    for (int x = 0; x <= boardSize; ++x)
    {
        for (int y = 0; y < boardSize; ++y)
        {
            for (int i = 0; i < 2; ++i)
            {
                // ���� ����� �ִٸ�
                if (board[x][y][i])
                {
                    // �ش� �κ��� ����� �̸� ���� ��հ� ���� ���߾�
                    // �ٽ� ������ �ִ��� Ȯ���Ѵ�
                    board[x][y][i] = false;

                    // ���� �� ���´ٸ� false�� 
                    if (!isBuilt(x, y, i))
                    {
                        board[x][y][i] = true;
                        return false;
                    }

                    // ���� �� �ִٸ�
                    board[x][y][i] = true;
                }
            }
        }
    }

    // true�� ��ȯ
    return true;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame)
{
    vector<vector<int>> answer;
    boardSize = n;

    for (int i = 0; i < build_frame.size(); ++i)
    {
        int x = build_frame[i][0];
        int y = build_frame[i][1];
        int a = build_frame[i][2];
        int b = build_frame[i][3];

        if (a) // �� ���
        {
            if (b) // ��ġ
            {
                if (isBuilt(x, y, 1))
                {
                   board[x][y][1] = true;
                }
            }
            else// ����
            {
                // ���� ����� ���� �� �ִ��� ���θ� �ľ�
                board[x][y][1] = false;

                // ���� �� ���ٸ�
                if (!isRemove())
                {
                    board[x][y][1] = true;
                }
            }
        }
        else // ��� �̶��
        {
            if (b) // ��ġ
            {
                if (isBuilt(x, y, 0))
                {
                    board[x][y][0] = true;
                }
            }
            else // ����
            {
                // ���� ����� ���� �� �ִ��� ���θ� �ľ�
                board[x][y][0] = false;

                // ���� �� ���ٸ�
                if (!isRemove())
                {
                    // �������
                    board[x][y][0] = true;
                }
            }
        }
    }

    // x = 0, y = 0 ���� �ݺ������� �������鼭 ���ʴ�� �־��ָ� ���ؿ� ����
    for(int x = 0; x <= boardSize; x++) 
    {
        for(int y = 0; y <= boardSize; y++) 
        {
            for(int i = 0; i < 2; i++) 
            {
                if(board[x][y][i]) 
                {
                    vector<int> temp;
                    temp.push_back(x);
                    temp.push_back(y);
                    temp.push_back(i);

                    answer.push_back(temp);
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
    vector<vector<int>> build_frame(m, vector<int>(4));

    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            cin >> build_frame[i][j];
        }
    }

    vector<vector<int>> s = solution(n, build_frame);
    for (int i = 0; i < s.size(); ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            cout << s[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
