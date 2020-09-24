#include <iostream>
#include <string>
#include <vector>
using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    
    // results는 1부터 시작하므로
    vector<vector<bool>> player(n + 1, vector<bool>(n + 1, false));
    
    for (int i = 0; i < results.size(); ++i)
    {
        player[results[i][0]][results[i][1]] = true;
    }
    
    for (int k = 1; k <= n; ++k)
    {
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                // player끼리의 기록이 있다면
                if (player[i][k] && player[k][j])
                {
                    player[i][j] = true;
                }
            }
        }
    }
    
    for (int i = 1; i <= n; ++i)
    {
        int cnt = 0;
        for (int j = 1; j <= n; ++j)
        {
            if (i == j)
            {
                continue;
            }
            // player의 승패가 기록되있다면
            if (player[i][j] || player[j][i])
            {
                cnt++;
            }
        }
        
        // 해당 선수를 제외하고 나머지 선수들과
        // 이겼는지 졌는지 확인이 가능하다면 그 선수는 순위를 매길수있다.
        // 즉 n - 1만큼 cnt가 있는지 확인하면 된다.
        if (cnt == n - 1)
        {
            answer++;
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

    vector<vector<int>> results(m, vector<int>(2));

    for (int i = 0; i < m; ++i)
    {
        cin >> results[i][0] >> results[i][1];
    }

    cout << solution(n, results) << "\n";

    return 0;
}