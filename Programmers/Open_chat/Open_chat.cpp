#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
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

vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string, string> users;
    int record_size = record.size();

    vector<string> log;
    for (int i = 0; i < record_size; ++i)
    {
        // 공백으로 나눈 문자열들을 저장한다.
        log = split(record[i], ' ');

        if (log[0] == "Enter")
        {
            // 해당 유저가 이미 있다면
            if (users.find(log[1]) != users.end())
            {
                // 해당 유저의 아이디가 기존과 다르다면
                if (users[log[1]] != log[2])
                {
                    // 아이디를 새로운것으로 교체
                    users[log[1]] = log[2];
                }
            }
            else // 해당 유저가 없다면
            {
                // 해당 유저를 추가
                users[log[1]] = log[2];
            }
        }
        else if (log[0] == "Change")
        {
            // 새로운 아이디로 교체
            users[log[1]] = log[2];
        }
    }

    for (int i = 0; i < record_size; ++i)
    {
        log = split(record[i], ' ');

        if (log[0] == "Enter")
        {
            answer.push_back(users[log[1]] + "님이 들어왔습니다.");
        }
        else if (log[0] == "Leave")
        { 
            answer.push_back(users[log[1]] + "님이 나갔습니다.");
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

    vector<string> record(n);

    cin.ignore();
    for (int i = 0; i < n; ++i)
    {
        getline(cin, record[i]);
    }

    solution(record);

    return 0;
}
