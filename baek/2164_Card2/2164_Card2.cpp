#include <iostream>
#include <queue>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    queue<int> q;

    for (int i = 1; i <= n; ++i)
    {
        q.push(i);
    }

    while (q.size() > 1)
    {
        // 제일 윗장의 카드를 버린다.
        q.pop();

        // 그 다음 카드를 맨 뒤로 보낸다.
        q.push(q.front());
        q.pop();
    }

    cout << q.front() << "\n";

    return 0;
}