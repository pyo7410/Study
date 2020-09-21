#include <iostream>
#include <queue>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // += 을 쓸거면 초기화를 잘하자!
    int answer = 0;
    int n;
    cin >> n;

    // 점수의 최대값이므로 가장 큰수를 우선적으로 더해주어야 한다.
    priority_queue<int, vector<int>, less<int>> slimes;
    int slime;
    for (int i = 0; i < n; ++i)
    {
        cin >> slime;
        slimes.push(slime);
    }

    int score;
    int new_slime;
    while (slimes.size() > 1)
    {
        new_slime = slimes.top();
        score = slimes.top();
        slimes.pop();

        new_slime += slimes.top();
        score *= slimes.top();
        slimes.pop();
        slimes.push(new_slime);

        answer += score;
    }

    cout << answer << "\n";

    return 0;
}