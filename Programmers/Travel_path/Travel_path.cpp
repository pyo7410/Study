#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> answer;

bool dfs(int cnt, string from, vector<vector<string>> tickets, vector<bool> &visit)
{
    answer.push_back(from);

    if (cnt == tickets.size())
    {
        return true;
    }

    for (int i = 0; i < tickets.size(); ++i)
    {
        // from이고 사용하지 않은 ticket이라면
        if (tickets[i][0] == from && !visit[i])
        {
            visit[i] = true;
            bool success = dfs(cnt + 1, tickets[i][1], tickets, visit);
            
            if (success)
            {
                return true;
            }

            // 경로를 찾지 못했고 tickets를 전부 사용하지 않았다면 false로 바꾸어
            // 아직 사용을 안한 다른 ticket을 for문에서 찾을 수 있게 해준다.
            visit[i] = false;
        }
    }

    // 마지막 까지 경로를 찾지 못했으므로 현재 경로를 빼고 false를 return
    answer.pop_back();
    return false;
}

vector<string> solution(vector<vector<string>> tickets) 
{
    vector<bool> visit(10001, false);

    // 만일 가능한 경로가 2개 이상일 경우 알파벳 순서가 앞서는 경로를 return 합니다
    sort(tickets.begin(), tickets.end());

    dfs(0, "ICN", tickets, visit);

    return answer;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<string>> tickets(n, vector<string>(2));
    for (int i = 0; i < n; ++i)
    {
        cin >> tickets[i][0] >> tickets[i][1];
    }

    for (auto s : solution(tickets))
    {
        cout << s << " ";
    }
    cout << "\n";

    return 0;
}