#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(int n, vector<int> times) 
{
    int times_size = times.size();
    long long st = 1;

    // times를 오름차순 정렬했으므로 가장 오래걸리는 심사관 기준으로
    // 가장 오래걸리는 시간을 저장한다.
    long long en = (long long)(times[times_size - 1]) * n;
    
    // en이 가장 큰 시간이므로
    // 987654321보다 더큰 숫자가 된다.
    long long answer = en;

    // 이진탐색을 하기위해서는 오름차순 정렬은 필수
    sort(times.begin(), times.end());

    while (st <= en)
    {
        long long mid = (st + en) / 2;
        long long sum = 0;

        for (int i = 0; i < times_size; ++i)
        {
            // 각 심사위원당 mid 시간동안 처리할 수 있는 인원의 수를 전부 더해준다.
            sum += mid / times[i];
        }

        // 심사위원이 mid 시간동안 처리한 인원의 수가 목표보다 적다면
        if (sum < n)
        {
            st = mid + 1;
        }
        else // 심사위원이 mid 시간동안 인원의 수가 크거나 같다면 즉, n 이상 처리가 가능하다는 의미
        {
            // 최소시간을 찾는것 이므로
            if (mid < answer)
            {
                answer = mid;
            }

            en = mid - 1;
        }
    }

    return answer;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    int m;
    cin >> m;

    vector<int> times(m);
    for (int i = 0; i < m; ++i)
    {
        cin >> times[i];
    }

    cout << solution(n, times) << "\n";

    return 0;
}