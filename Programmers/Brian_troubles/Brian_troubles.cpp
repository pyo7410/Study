#include <iostream>
#include <string>
using namespace std;

// char���� 256�� �̹Ƿ�
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

// ���� ������ ������ ��� �Լ� ���� �ʱ�ȭ �ڵ带 �� �ۼ����ּ���.
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
