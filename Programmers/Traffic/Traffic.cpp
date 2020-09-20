#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

// https://musket-ade.tistory.com/entry/%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%A8%B8%EC%8A%A4-1%EC%B0%A8-%EC%B6%94%EC%84%9D-%ED%8A%B8%EB%9E%98%ED%94%BD

// split 사용법
// https://ssungkang.tistory.com/entry/C-string-%EB%AC%B8%EC%9E%90%EC%97%B4-%EB%82%98%EB%88%84%EB%8A%94-split

// input 문자열을 받아 delimiter에 입력된 문자가 나올때까지 temp에 저장하고
// temp를 result 벡터에 담아
// delimiter로 나눈 문자열을 반환
vector<string> split(string input, char delimiter)
{
    vector<string> result;
    stringstream ss(input);
    string temp;

    while (getline(ss, temp, delimiter))
    {
        result.push_back(temp);
    }

    return result;
}

int solution(vector<string> lines) 
{
    int answer = 0;
    int lines_size = lines.size();

    // lines에 담긴 문자열들을 분리한 문자열을 저장할 벡터
    // 0 : 날짜, 1 : 응답 완료 시간, 2 : 처리 시간
    vector<string> log(lines_size);
    vector<int> start; // 시작 시간을 담을 벡터
    vector<int> end; // 완료 시간을 담을 벡터

    // 시작 시간
    int start_time = 0;
    // 완료 시간
    int end_time = 0;
    // 처리 시간
    int process_time = 0;
    for (int i = 0; i < lines_size; ++i)
    {
        // lines를 공백으로 나눔
        log = split(lines[i], ' ');

        // 완료 시간
        // ':' 을 기준으로 응답 완료 시간을 잘라 시간은 3600000밀리초, 분은 60000밀리초, 초는 1000밀리초를 곱하고 전부 더해주어
        // hh:mm:ss 형식으로 되있는 시간을 전부 밀리초 형식으로 바꾸어준다.
        end_time = stoi(split(log[1], ':')[0]) * 3600000 + stoi(split(log[1], ':')[1]) * 60000 + stof(split(log[1], ':')[2]) * 1000;

        // 처리 시간
        // 처리시간 또한 초로 되어 있으므로 1000을 곱해 밀리초로 바꾸어준다.
        // - 1을 한 이유는 시작시간과 끝시간이 포함되있기 때문에 -1을 해주어야한다.
        process_time = stof(log[2]) * 1000 - 1;

        end.push_back(end_time);
        start.push_back(end_time - process_time);
    }

    for (int i = 0; i < lines_size; ++i)
    {
        int cnt = 0;

        // 초당 최대 처리량은 요청의 응답 완료 여부에 관계없이 
        // 임의 시간부터 1초(=1,000밀리초)간 처리하는 요청의 최대 개수 이므로
        // 범위는 시작시간 -1초 즉 -1000 밀리초가 되지만
        // 시간은 시작시간과 끝시간이 포함되 있으므로 -1을한 999를 빼준다.
        int range = start[i] - 999;

        // 각 처리의 시작시간을 범위의 시작점으로 잡아 그때마다 모든 요청들의 시간이
        // 해당 범위에 들어가는지 비교해주면 된다.
        for (int j = 0; j < lines_size; ++j)
        {
            // 시작지점이 범위안에 있으면 종료지점은 상관없다.
            // 시작지점이 범위보다 크거나 같고, 현재 시작지점보다 작거나 같을경우
            // range의 처리시간에 포함된다.
            if (range <= start[j] && start[j] <= start[i])
            {
                cnt++;
            }
            else if (range >= start[j] && end[j] >= range) 
            {
                // 시작지점이 범위보다 이전에 있고 해당 처리의 끝지점이 범위 밖에 있으면
                // range의 처리시간에 포함된다.
                cnt++;
            }
        }

        // 최대 처리 개수를 찾는 것 이므로
        if (answer < cnt)
        {
            answer = cnt;
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
    
    vector<string> lines(n);
    string temp;
    
    cin.ignore();

    for (int i = 0; i < n; ++i)
    {
        getline(cin, lines[i]);
    }

    cout << solution(lines) << "\n";

    return 0;
}