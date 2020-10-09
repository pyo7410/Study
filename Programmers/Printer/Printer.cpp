#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;
class Info
{
public:
    // 중요도 저장
    int prior;
    // 위치 저장
    int idx;
    
    Info(int prior, int idx)
    {
        this->prior = prior;
        this->idx = idx;
    }
};

int solution(vector<int> priorities, int location) {
    int answer = 1;
    priority_queue<int, vector<int>, less<int>> pq;
    queue<Info> q;
    
    for (int i = 0; i < priorities.size(); ++i)
    {
        pq.push(priorities[i]);
        q.push(Info(priorities[i], i));
    }
    
    while (!pq.empty())
    {
        if (q.front().prior == pq.top())
        {
            // 요청한 인쇄이므로 반복문 탈출
            if (q.front().idx == location)
            {
                break;
            }

            // 요청한 인쇄가 아니라면 출력
            answer++;
            q.pop();
            pq.pop();

            continue;
        }

        // 우선순위가 같을때 까지 큐에서 뒤로보냄
        Info temp = q.front();
        q.pop();
        q.push(temp);
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

    vector<int> priorities(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> priorities[i];
    }

    int location;
    cin >> location;

    cout << solution(priorities, location) << "\n";

    return 0;
}