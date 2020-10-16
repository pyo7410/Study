#include <iostream>
#include <string>
#include <stack>
using namespace std;

int solution(string s)
{
    int answer = 0;
    stack<char> stk;
    
    // 스택으로 제거가 불가능한 문자는
    // 저장해둘수 있다.
    for (char c : s)
    {
        if (stk.empty() || stk.top() != c)
        {
            stk.push(c);
        }
        else
        {
            stk.pop();
        }
    }
    
    answer = stk.empty();

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