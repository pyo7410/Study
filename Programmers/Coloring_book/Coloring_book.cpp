#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

int M, N;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int visit[101][101];

int bfs(vector<vector<int>> picture, int i, int j, int color)
{
    int result = 1;
    queue<pair<int, int>> q;
    q.push({i, j});
    visit[i][j] = true;

    while (!q.empty())
    {
        int x = q.front().second;
        int y = q.front().first;
        q.pop();

        for (int k = 0; k < 4; ++k)
        {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (nx >= 0 && ny >= 0 && nx < N && ny < M)
            {
                if (!visit[ny][nx] && picture[ny][nx] == color)
                {
                    visit[ny][nx] = true;                    
                    q.push({ny, nx});
                    result++;
                }
            }
        }    
    }
    
    return result;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;

    M = m;
    N = n;

    memset(visit, false, sizeof(visit));

    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (picture[i][j] > 0 && !visit[i][j])
            {
                number_of_area++;
                int max_size = bfs(picture, i, j, picture[i][j]);
                if (max_size > max_size_of_one_area)
                {
                    max_size_of_one_area = max_size;
                }
            }
        }
    }
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int m, n;
    cin >> m >> n;

    vector<vector<int>> picture(m, vector<int>(n));

    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> picture[i][j];
        }
    }

    solution(m, n, picture);

    return 0;
}