#include <iostream>
#include <string>
#include <vector>
#define MAX 987654321;
using namespace std;

int solution(string s)
{
    int answer = 0;
    int min = MAX;
    int len_s = s.length();
    vector<pair<string, int>> vec;

    // 길이가 1인 문자열이 입력일 경우
    if (len_s == 1)
    {
        return 1;
    }

    // 문자열의 제일 앞에서 부터 정해진 길이만큼 잘라야한다.
    // 즉, 최대 len / 2 만큼만 자를 수 있다.

    // i -> 가져올 문자열의 수
    for (int i = 1; i <= len_s / 2; ++i)
    {
        
        // 초기 값을 넣어준다.
        vec.push_back({s.substr(0, i), 1});

        // j -> 전체 문자열
        for (int j = i; j < len_s; j += i)
        {
            string temp = s.substr(j, i);

            // 만약 직전에 넣었던 문자열과
            // 다르다면
            if (vec.back().first != temp)
            {
                vec.push_back({temp, 1});
            }
            else // 같다면
            {
                vec.back().second += 1;   
            }
        }

        // 압축 문자열 생성
        string comp_str = "";
        for (int j = 0; j < vec.size(); ++j)
        {
            // 문자열이 한번만 쓰였을 경우
            if (vec[j].second == 1)
            {
                comp_str += vec[j].first;
            }
            else // 문자열이 여러번 쓰였을 경우
            {
                comp_str += (to_string(vec[j].second) + vec[j].first);
            }
        }

        int len_comp_str = comp_str.length();

        // 최소값이면 값 변경
        if (min > len_comp_str)
        {
            min = len_comp_str;
        }

        // 다른 문자열의 수를 다시 해야하므로 초기화
        vec.clear();
    }

    answer = min;

    return answer;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s;
    cin >> s;
    cout << solution(s) << "\n";

    return 0;
}
