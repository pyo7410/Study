#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0;
    int sum = 0;

    //주어진 배열을 오름차순으로 정렬한 뒤 앞에서부터 차례대로 더해간 뒤 budget 값보다 크면 지금까지 더한 개수를 반환하면 된다

    sort(d.begin(), d.end());

    for (int num : d)
    {
        sum += num;

        if (sum > budget)
        {
            break;
        }
        else
        {
            answer++;
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

    vector<int> d(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> d[i];
    }

    int budget;
    cin >> budget;

    cout << solution(d, budget) << "\n";

    return 0;
}