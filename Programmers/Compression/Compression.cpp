#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> solution(string msg) 
{
    vector<int> answer;
    int idx;
    unordered_map<string, int> dict;
    string letter = "";

    // 문제에서 사전의 인덱스는 1부터 시작하므로
    // 알파벳은 총 26개
    for (idx = 1; idx < 27; ++idx)
    {
        letter = 'A' + idx - 1;
        dict[letter] = idx;
    }

    int len = msg.length();

    for (int i = 0; i < len; ++i)
    {
        string temp = "";
        temp += msg[i];
        int j = i;
        int cnt = 0;

        // 글자수를 +1 하며 사전에 없을때까지 찾는다.
        while (dict.find(temp) != dict.end())
        {
            cnt++;
            j++;
            temp += msg[j];
        }

        // 한자리의 글자수는 반드시 있고 사전에 없는 문자열이
        // 두자리라면 마지막 자리의 위치부터
        // 시작해야 하므로 -1을 해준다.
        i += cnt - 1;
        dict[temp] = idx++;

        // 글자수 + 1을 한 상태 즉, 사전에 없는 문자이므로
        // 맨 뒤에 글자수를 빼어 기존에 사전에있었던 문자로 바꾸어준다.
        temp.pop_back();
        answer.push_back(dict[temp]);
    }

    return answer;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string msg;
    cin >> msg;

    solution(msg);

    return 0;
}