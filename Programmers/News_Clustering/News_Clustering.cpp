#include <iostream>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    map<string, int> m1;
    map<string, int> m2;

    int len1 = str1.length();
    int len2 = str2.length();

    // 문자열을 대문자로 변환시켜준다.
    transform(str1.begin(), str1.end(), str1.begin(), ::toupper);
    transform(str2.begin(), str2.end(), str2.begin(), ::toupper);

    // str1에서 두 글자씩 끊어서 조건에 맞는 다중집합을 만든다.
    for (int i = 0; i < len1 - 1; ++i)
    {
        // 둘 중하나라도 알파벳이 아니라면 다중집합이 될 수 없다.
        if (!isalpha(str1[i]) || !isalpha(str1[i + 1]))
        {
            continue;
        }
        else
        {
            string temp = "";
            temp += str1[i];
            temp += str1[i + 1];
            m1[temp] += 1;
        }
    }

    // str2에서 두 글자씩 끊어서 조건에 맞는 다중집합을 만든다.
    for (int i = 0; i < len2 - 1; ++i)
    {
        // 둘 중하나라도 알파벳이 아니라면 다중집합이 될 수 없다.
        if (!isalpha(str2[i]) || !isalpha(str2[i + 1]))
        {
            continue;
        }
        else
        {
            string temp = "";
            temp += str2[i];
            temp += str2[i + 1];
            m2[temp] += 1;
        }
    }

    // 교집합과 합집합의 개수를 저장
    int a = 0, b = 0;
    // str1 기준으로 반복
    // m1, m2의 길이는 어차피 m1에서 포함되지 않았다면 전부
    // 합집합이므로 생각하지 않아도 된다.
    for (auto iter : m1)
    {
        // 만약 str2의 다중집합에 포함된 문자라면
        if (!(m2.find(iter.first) == m2.end()))
        {
            // a는 교집합이므로 m1, m2에서 최소값을 저장
            a += min(iter.second, m2[iter.first]);
            // b는 합집합이므로 m1, m2에서 최대값을 저장
            b += max(iter.second, m2[iter.first]);
            // 반복문이 끝나고 남은 다중집합의 개수는 전부 합집합으로 만들어야하므로
            // 사용된 다중집합은 빼주어야한다.
            m2.erase(iter.first);
        }
        else
        {
            // str2의 다중집합에 포함되지 않았다면
            // 교집합은 존재할 수 없고, 합집합 b 에 해당 문자열의 개수를 더해준다.
            b += iter.second;
        }
    }

    // 반복문을 통하여 m1에서의 모든 문자열을 봤으므로
    // m2에 남은 문자열은 자동으로 합집합이 되게 된다.
    for (auto iter : m2)
    {
        b += iter.second;
    }

    double result;
    // 문제 조건에 맞추어 둘다 0이라면 1
    // 65536을 바로 return 해도 된다.
    if (a == 0 && b == 0)
    {
        result = 1.0;
    }
    else
    {
        result = (double)a / (double)b;
    }

    // 곱하고 소수점을 버리기 위해 int 형인 answer에 저장
    answer = result * 65536;

    return answer;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string str1, str2;

    getline(cin, str1);
    getline(cin, str2);

    cout << solution(str1, str2) << "\n";

    return 0;
}