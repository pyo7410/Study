#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> money) 
{
    int answer = 0;
    int money_size = money.size();

    // 첫번째 집부터 탐색
    vector<int> dp_first(money_size, 0);
    // 두번째 집부터 탐색
    vector<int> dp_second(money_size, 0);

    dp_first[0] = money[0];
    // 첫번째집 부터 훔치므로 그 다음집은 안훔치게 된다.
    // 즉, 첫번째집에서 훔친금액이 유지된다.
    dp_first[1] = money[0];

    // 두번째 집부터 훔치므로 그 이전인 첫번째집에서는
    // 0원이 된다.
    dp_second[0] = 0;
    dp_second[1] = money[1];
    
    // 첫번째 집부터
    // 첫번째 집과 마지막 집은 이어져 있음을 주의할것!
    for (int i = 2; i < money_size - 1; ++i)
    {
        // dp_first[n - 1]은 dp_first[n]이전까지 훔친 모든 돈의 합이 들어있다.
        dp_first[i] = max(dp_first[i - 2] + money[i], dp_first[i - 1]);
    }

    // 두번째 집부터
    // 두번째 집부터는 맨 마지막집까지 훔칠수 있다
    for (int i = 2; i < money_size; ++i)
    {
        // dp_second[n - 1]은 dp_second[n]이전까지 훔친 모든 돈의 합이 들어있다.
        dp_second[i] = max(dp_second[i - 2] + money[i], dp_second[i - 1]);
    }

    // 첫번째 부터 탐색한집은 마지막집 이전까지 이므로 -2를 해야한다.
    answer = max(dp_first[money_size - 2], dp_second[money_size - 1]);

    return answer;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    vector<int> money(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> money[i];
    }

    cout << solution(money) << "\n";

    return 0;
}