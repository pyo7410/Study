#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// 신호는 왼쪽으로 가므로
// 오른쪽에 있는 탑은 전혀 신경쓸 필요가 없다.
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    int tower;
    // 인덱스와 타워의 높이를 저장
    stack<pair<int, int>> st;
    for (int i = 0; i < n; ++i)
    {
        cin >> tower;

        while (!st.empty())
        {
            if (st.top().second > tower)
            {
                // 수신을 받은 타워가 존재한다면 그 이전의 pop했던 tower들은
                // 현재 tower보다 낮다는 의미이므로 무시해도 된다.
                cout << st.top().first << " ";
                break;
            }

            st.pop();
        }

        if (st.empty())
        {
            cout << 0 << " ";
        }

        st.push({i + 1, tower});
    }

    return 0;
}