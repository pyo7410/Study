#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;

    // MST 에서는 간선의 개수는 항상 N - 1개
    // 이 문제에서는 항상 연결 그래프를 이루므로
    // N - 1 을 출력하면 최소 개수가 된다.

    while (t--)
    {
        int n, m;
        cin >> n >> m;

        while(m--)
        {
            int a, b;
            cin >> a >> b;
        }

        cout << n - 1 << "\n";
    }

    return 0;
}