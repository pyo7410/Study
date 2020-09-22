#include <iostream>
#include <vector>
using namespace std;

int block[501][501];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int h, w;
    cin >> h >> w;

    int block_height;
    for (int i = 1; i <= w; ++i)
    {
        cin >> block_height;
        
        for (int j = 1; j <= block_height; ++j)
        {
            block[j][i] = 1;
        }
    }

    int answer = 0;
    for (int i = 1; i <= h; ++i)
    {
        int cnt = 0;
        bool left_block = false;
        bool right_block = false;
        for (int j = 1; j <= w; ++j)
        {
            if (block[i][j] == 1 && !left_block)
            {
                left_block = true;
            }
            else if (block[i][j] == 1 && left_block)
            {
                right_block = true;
            }
            else if (left_block && block[i][j] == 0)
            {
                cnt += 1;
            }

            if (left_block && right_block)
            {
                // 오른쪽블럭이 왼쪽블럭으로 바뀌므로 왼쪽블록은 존재하게 된다.
                right_block = false;        
                answer += cnt;
                cnt = 0;
            }
        }
    }

    cout << answer << "\n";

    return 0;
}