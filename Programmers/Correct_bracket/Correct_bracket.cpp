#include <string>
#include <iostream>
#include <stack>
using namespace std;

bool solution(string s)
{
    bool answer = true;

    stack<char> stk;

    for (char c : s)
    {
        if (c == '(')
        {
            stk.push(c);
        }
        else
        {
            if (stk.empty())
            {
                return false;
            }

            stk.pop();
        }
    }

    if (!stk.empty())
    {
        return false;
    }

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