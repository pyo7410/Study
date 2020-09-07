#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// https://covenant.tistory.com/162

bool check (vector<int> stones, int k, int mid)
{
    int cnt = 0;

    for (int i = 0; i < stones.size(); ++i)
    {
        // 현재 건널 인원의 수가 stones[i]의 숫자보다 큰 경우
        // 즉, stones의 i 번째의 돌이 적혀있는 횟수가 다 쓰여 0이 되어 버리는 경우

        // if else 문에 의해 연속으로 cnt가 +1 되야 k와 같거나 커진다.
        if (stones[i] < mid)
        {
            // 때문에 0이되는 돌의 갯수를 +1 하여
            cnt++;

            // 0이 연속을 K개가 나오는 구간이 된다!
            // 0이 되는 돌의 갯수가
            // k 와 같거나 커지면 한번에 못건너게 되므로
            // mid 이전의 인원만 건널 수 있다는 의미이므로
            if (cnt >= k)
            {
                return false;
            }
        }
        else
        {
            cnt = 0;
        }
    }

    return true;
}

int solution(vector<int> stones, int k) {
    int answer = 0;
    
    // 건널 수 있는 인원은 최대 2억명
    // 최대 무한대 이지만 stones에는 2억까지 들어가므로
    int right = *max_element(stones.begin(), stones.end());
    // 건널 수 있는 인원은 최소 1명
    int left = 1;

    while (left <= right)
    {
        // 현재 건널 인원 수
        int mid = (left + right) / 2;
        if (check(stones, k, mid))
        {
            left = mid + 1;
            if (answer < mid)
            {
                answer = mid;
            }
        }
        else
        {
            right = mid - 1;
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

    vector<int> stones(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> stones[i];

    }

    int k;
    cin >> k;

    cout << solution(stones, k) << "\n";
    
    return 0;
}
