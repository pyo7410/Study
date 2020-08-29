#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//기둥은 바닥 위에 있거나 보의 한쪽 끝 부분 위에 있거나,
//또는 다른 기둥 위에 있어야 합니다.

//보는 한쪽 끝 부분이 기둥 위에 있거나,
//또는 양쪽 끝 부분이 다른 보와 동시에 연결되어 있어야 합니다.


// x, y를 인덱스가 아닌 x축 y축의 좌표로 생각한다.
// n은 5 ~ 100 이하인 자연수
// type -> 0 : 기둥, 1 : 보
// 시작 지점만 저장한다.
bool board[101][101][2]; // x, y, type
int boardSize;

bool check(int x, int y) {
    if(x < 0 || y < 0 || x > boardSize || y > boardSize) {
        return false;
    }
    return true;
}

// 보 조건
bool isBuilt(int x, int y, int type)
{
    if (type) // 보 일때
    {
        // 한쪽 끝 부분이 기둥 위거나
        // 보는 오른쪽으로 설치 됨을 유의
        if((check(x, y - 1) && board[x][y - 1][0]) || (check(x + 1, y - 1) && board[x + 1][y - 1][0]))
        {
            return true;
        }

        // 양쪽 끝 부분이 다른 보와 연결되있다면
        // x - 1에서 시작하는 보와 x + 1에서 시작하는 보
        if((check(x - 1, y) && check(x + 1, y)) && board[x - 1][y][1] && board[x + 1][y][1])
        {
            return true;
        }
    }
    else // 기둥 일때
    {
        // 바닥이거나
        if (y == 0)
        {
            return true;
        }

        // 보의 한쪽 끝 부분 위에 있거나
        // 왼쪽 보의 끝 부분이냐, 오른쪽 보의 시작 부분이냐
        // 보는 오른쪽으로 설치 됨을 유의
        if((check(x - 1, y) && board[x - 1][y][1]) || board[x][y][1])
        {
            return true;
        }

        // 다른 기둥위라면
        if(check(x, y - 1) && board[x][y - 1][0])
        {
            return true;
        }
    }

    return false;
}

// 기둥 조건
// 미리 기둥과 보를 지우고
bool isRemove()
{
    // 모든 보와 기둥에 대해서 조사하여
    for (int x = 0; x <= boardSize; ++x)
    {
        for (int y = 0; y < boardSize; ++y)
        {
            for (int i = 0; i < 2; ++i)
            {
                // 보랑 기둥이 있다면
                if (board[x][y][i])
                {
                    // 해당 부분을 지우고 미리 지운 기둥과 보에 맞추어
                    // 다시 지을수 있는지 확인한다
                    board[x][y][i] = false;

                    // 만약 못 짓는다면 false를 
                    if (!isBuilt(x, y, i))
                    {
                        board[x][y][i] = true;
                        return false;
                    }

                    // 지을 수 있다면
                    board[x][y][i] = true;
                }
            }
        }
    }

    // true를 반환
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

        if (a) // 보 라면
        {
            if (b) // 설치
            {
                if (isBuilt(x, y, 1))
                {
                   board[x][y][1] = true;
                }
            }
            else// 삭제
            {
                // 먼저 지우고 지울 수 있는지 여부를 파악
                board[x][y][1] = false;

                // 지울 수 없다면
                if (!isRemove())
                {
                    board[x][y][1] = true;
                }
            }
        }
        else // 기둥 이라면
        {
            if (b) // 설치
            {
                if (isBuilt(x, y, 0))
                {
                    board[x][y][0] = true;
                }
            }
            else // 삭제
            {
                // 먼저 지우고 지울 수 있는지 여부를 파악
                board[x][y][0] = false;

                // 지울 수 없다면
                if (!isRemove())
                {
                    // 원래대로
                    board[x][y][0] = true;
                }
            }
        }
    }

    // x = 0, y = 0 부터 반복문으로 돌려가면서 차례대로 넣어주면 기준에 부합
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
