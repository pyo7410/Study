#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    for (int test_case = 1; test_case <= 10; ++test_case)
    {
        int len;
        cin >> len;

        string str;
        cin >> str;

        stack<char> s;
        s.push(str[0]);
        for (int i = 1; i < len; ++i)
        {
            if (str[i] == '(')
            {
                s.push(str[i]);
            }
            else if (str[i] == '[')
            {
                s.push(str[i]);
            }
            else if (str[i] == '{')
            {
                s.push(str[i]);
            }
            else if (str[i] == '<')
            {
                s.push(str[i]);
            }
            else if (str[i] == ')' && s.top() == '(')
            {
                s.pop();
            }
            else if (str[i] == ']' && s.top() == '[')
            {
                s.pop();
            }
            else if (str[i] == '}' && s.top() == '{')
            {
                s.pop();
            }
            else if (str[i] == '>' && s.top() == '<')
            {
                s.pop();
            }
            else
            {
                break;
            }
        }

        if (!s.empty())
        {
            cout << "#" << test_case << " " << 0 << "\n";
        }
        else
        {
            cout << "#" << test_case << " " << 1 << "\n";
        }    
    }
    
    return 0;
}
