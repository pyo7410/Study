#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> routes) 
{
    // 차는 1대 이상이므로
    // 카메라는 무조건 한개이상은 설치되야 한다.
    int answer = 1;

    // 출발지점이 제일 작은 지점을 오름차순으로 정렬
    // 먼저 출발한 차와 조금 더 늦게 출발한 차를 비교해가기 위함
    sort(routes.begin(), routes.end());

    // 끝나는 지점을 range로 잡는다
    int range = routes[0][1];
    for (int i = 0; i < routes.size() - 1; ++i)
    {
        // range 안에 끝나는 지점이 존재한다면
        // 해당 range의 과속카메라로 처리 가능
        if (range > routes[i][1])
        {
            range = routes[i][1];
        }

        // 출발지점이 오름차순이므로 어찌됬든 다음으로 출발지점이 짧은 지점은
        // 항상 현재 지점의 출발지점보다 큰 수가 되므로
        // 현재지점 다음으로 출발지점이 짧은 지점의 시작지점이 range범위 밖이라면
        // 새로운 카메라를 설치한다.
        if (range < routes[i + 1][0])
        {
            answer++;
            range = routes[i + 1][1];
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

    vector<vector<int>> routes(n, vector<int>(2));
    for (int i = 0; i < n; ++i)
    {
        cin >> routes[i][0] >> routes[i][1];
    }

    cout << solution(routes) << "\n";

    return 0;
}