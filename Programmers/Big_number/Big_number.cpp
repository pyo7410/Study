#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> temp(5, 0);

string solution(string number, int k) 
{
    string answer = "";
    
    // k 개의 수를 뺀 최종 수의 길이
    int numSize = number.size() - k;
    // 시작 지점
    int start = 0;

    // k 개의 수를 뺀 최종 수를 구하기 위한 반복문
    for (int i = 0; i < numSize; ++i)
    {
        // 큰 수를 저장
        // 아무런 값이 없으므로 시작 지점 값으로 초기화
        char maxNum = number[start];
        // 큰 수의 인덱스
        int maxIdx = start;

        // number의 길이가 10이고 k = 4라면
        // 만약 start가 0 이고 k 가 4 라면
        // j[5] ~ j[len] 까지 더 큰 숫자가 있더라도
        // answer의 길이가 6이어야 하므로 고르지 못하기 때문이다.
        for (int j = start; j <= k + i; ++j)
        {
            if (maxNum < number[j])
            {
                maxNum = number[j];
                maxIdx = j;
            }
        }

        // 큰 수의 인덱스의 다음 위치로 start를 옮긴다
        start = maxIdx + 1;

        // 큰 수를 정답에 넣어준다.
        answer += maxNum;
    }

    return answer;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string number;
    cin >> number;

    int k;
    cin >> k;

    cout << solution(number, k) << "\n";

    return 0;
}