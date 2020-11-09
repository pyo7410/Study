#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> vec(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> vec[i];
    }

    sort(vec.begin(), vec.end(), greater<>());

    // 이 문제에서는 가장 큰 수와 두번째 큰 수를 벗어날 일이 없으므로
    int first_big = vec[0];
    int second_big = vec[1];

    int answer = 0;
    
    // 총 갯수는 m개 이므로 m개를 k + 1 즉, k개의 가장 큰 수와 1개의 두번째 큰 수의 길이를
    // 나누어 해당 수열이 m개에서 몇번 반복되는지 구하고 그 수에 가장 큰 수의 수인 k를 곱하면
    // 가장 큰 수의 총 개수가 나오게 된다.
    // k + 1로 m이 나눠지지 않는다면 가장 큰 수가 나머지만큼 더해질 수 잇으므로 해당 수도 더해야한다.
    int cnt = (m / (k + 1)) * k;
    cnt += m % (k + 1);

/*
    while (m)
    {
        for (int i = 0; i < k; ++i)
        {
            answer += first_big;
            m -= 1;
        }

        answer += second_big;
        m -= 1;
    }
*/

    answer += cnt * first_big; // 가장 큰 수 더하기

    // 총 m 개에서 가장 큰 수의 갯수를 빼면 두번째 큰 수의 개수가 된다.
    answer += (m - cnt) * second_big; // 두번째 큰 수 더하기
    
    cout << answer << "\n";

    return 0;
}