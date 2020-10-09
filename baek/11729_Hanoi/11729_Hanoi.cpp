#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> ans;

void hanoi(int n, int from, int by, int to)
{
    if (n == 1)
    {
        // n == 1 즉, 마지막 원판은 바로 세번째로 옮기면 되므로
        // 바로 경로를 입력한다.
        ans.push_back({from, to});
    }
    else
    {
        // 원판을 전부 2번째로 옮긴다.
        hanoi(n - 1, from, to, by);
        ans.push_back({from, to});
        // 옮긴 원판을 전부 3번째로 옮기면 완성
        hanoi(n - 1, by, from, to);
    }
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    hanoi(n, 1, 2, 3);

    cout << ans.size() << "\n";

    for (auto iter : ans)
    {
        cout << iter.first << " " << iter.second << "\n";
    }

    return 0;
}