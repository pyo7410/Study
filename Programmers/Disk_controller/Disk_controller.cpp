#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// 작업시간이 큰 순으로 정렬
struct cmp
{
    bool operator()(vector<int> a, vector<int> b)
    {
        return a[1] > b[1];
    }
};

int solution(vector<vector<int>> jobs) 
{
    int answer = 0;
    int idx = 0;
    int time = 0;

    // 들어온 시간이 작은 순으로 정렬
    sort(jobs.begin(), jobs.end());

    // min_heap
    priority_queue<vector<int>, vector<vector<int>>, cmp> pq;

    // jobs를 다 하고
    // 큐가 비어있을때까지 반복
    while (!pq.empty() || idx < jobs.size())
    {
        // 들어올 jobs이 남아있고, 들어올 jobs의 들어온 시간이 현재시간보다 작거나 같다면
        if (jobs.size() > idx && time >= jobs[idx][0])
        {
            // 우선순위 큐에 추가
            pq.push(jobs[idx++]);

            // time보다 작은 다른작업이 더 들어왔을수도 있으므로 다시확인
            continue;
        }

        // 큐가 비어있지 않다면
        if (!pq.empty())
        {
            // 현재시간에 작업이 끝날때 까지 즉 작업시간을 추가
            time += pq.top()[1];
            // 작업 시간에 대기시간을 추가
            // 현재시간 - 들어온 시간
            // 즉, 대기시간부터 완료될 시간까지 걸린시간을 계산한다.
            answer += time - pq.top()[0];
            // 작업이 끝났으므로 우선순위 큐에서 제거
            pq.pop();
        }
        else // 큐가 비어있다면
        {
            // 다음 작업 시간으로 넘겨준다.
            time = jobs[idx][0];
        }
        
    }

    // 평균을 구하는 문제 이므로
    answer /= jobs.size();

    return answer;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> jobs(n, vector<int>(2));

    for (int i = 0; i < n; ++i)
    {
        cin >> jobs[i][0] >> jobs[i][1];
    }

    cout << solution(jobs) << "\n";

    return 0;
}