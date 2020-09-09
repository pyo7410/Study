#include <iostream>
#include <string>
using namespace std;

// char형은 256개 이므로
bool check[256];

class Info {
public:
    int start, end, cnt;

    Info(int start, int end, int cnt) {
        this->start = start;
        this->end = end;
        this->cnt = cnt;
    }
};

Info getStrInfo(string sentence, int idx)
{
    int start = idx, end;
    int cnt = 0;

    for (; idx < sentence.length(); ++idx)
    {

    }

    return Info()
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
string solution(string sentence) {
    string answer = "";
    string crypt = "";
    int len = sentence.length();
    int idx = 0;

    for (int i = 0; i < len; ++i)
    {
        if (sentence[i] == ' ')
        {
            return "invalid";
        }
    }

    for (int i = 0; i < len; ++i)
    {
        if (islower(sentence[i]))
        {
            
        }
    }

    return answer;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    string sentence;
    cin >> sentence;

    cout << solution(sentence) << "\n";
    
    return 0;
}
