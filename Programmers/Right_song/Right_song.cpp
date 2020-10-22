#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

vector<string> split(string input, char delimeter)
{
    vector<string> result;
    stringstream ss(input);
    string temp;

    while (getline(ss, temp, delimeter))
    {
        result.push_back(temp);
    }

    return result;
}

bool isInclude(string code, string m, int idx)
{
    for (int i = 0; i < m.length(); ++i)
    {
        if (code[i + idx] != m[i])
        {
            return false;
        }
        else
        {
            // # 이 붙은 코드들을 처리하기 위함
            if ((i + 1 < m.length() && m[i + 1] == '#') || (i + 1 + idx < code.length() && code[i + 1 + idx] == '#'))
            {
                if (i + 1 >= m.length() || i + 1 + idx >= code.length())
                {
                    return false;
                }
                if (!(code[i + 1 + idx] == '#' && m[i + 1] == '#'))
                {
                    return false;
                }
            }
        }
    }

    return true;
}

string solution(string m, vector<string> musicinfos) 
{
    string answer = "(None)";
    pair<string, int> result;
    int play_time, real_time;
    int cnt = musicinfos.size();
    vector<string> log;
    vector<string> start_log;
    vector<string> end_log;

    result.first = "(None)";
    result.second = 0;
    for (int i = 0; i < cnt; ++i)
    {
        log = split(musicinfos[i], ',');

        real_time = log[3].length();

        start_log = split(log[0], ':');
        end_log = split(log[1], ':');        

        play_time = (stoi(end_log[0]) * 60 + stoi(end_log[1])) - (stoi(start_log[0]) * 60 + stoi(start_log[1]));

        // 음수가 나온다면 양수로 바꾸어주어야 한다.
        if (play_time < 0)
        {
            play_time *= -1;
        }

        int idx = 0;
        string codes = "";
        // 플레이 시간에 맞게 코드를 추가한다.
        for (int j = 0; j < play_time; ++j)
        {
            if (idx == real_time)
            {
                idx = 0;
            }

            // # 이 붙은 코드들을 처리하기 위함
            if (idx + 1 < real_time && log[3][idx + 1] == '#')
            {
                codes += log[3][idx];
                codes += log[3][idx + 1];
                idx += 2;
            }
            else
            {
                codes += log[3][idx];
                idx++;
            }
        }

        // 문제의 조건중에 
        // 조건이 일치하는 음악이 여러 개일 때에는 라디오에서 재생된 시간이 제일 긴 음악 제목을 반환한다. 
        // 재생된 시간도 같을 경우 먼저 입력된 음악 제목을 반환한다.
        // 를 주의!
        for (int j = 0; j < codes.length(); ++j)
        {
            if (codes[j] == m[0] && isInclude(codes, m, j))
            {
                if (result.first != "(None)")
                {
                    if (result.second < play_time)
                    {
                        result.first = log[2];
                        result.second = play_time;
                    }
                }
                else
                {
                    result.first = log[2];
                    result.second = play_time;
                }
            }
        }
    }

    answer = result.first;

    return answer;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    string m;

    cin >> n >> m;

    vector<string> musicinfos(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> musicinfos[i];
    }

    cout << solution(m, musicinfos) << "\n";

    return 0;
}
