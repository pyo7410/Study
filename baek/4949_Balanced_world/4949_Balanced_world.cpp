#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    

    while(true)
    {
        string s;
        getline(cin, s);

        if (s == ".")
        {
            break;
        }

        stack<char> st;
        bool check = false;

        for (int i = 0; i < s.length(); ++i)
        {
            if (s[i] == '(' || s[i] == '[')
            {
                st.push(s[i]);
            }
            else if (s[i] == ')')
            {
                if (!st.empty() && st.top() == '(')
                {
                    st.pop();
                }
                else
                {
                    cout << "no\n";
                    check = true;
                    break;
                }
            }
            else if (s[i] == ']')
            {
                if (!st.empty() && st.top() == '[')
                {
                    st.pop();
                }
                else
                {
                    cout << "no\n";
                    check = true;
                    break;
                }
            }
        }

        // 결과가 중복으로 출력이 안되게 막아준다.
        if (check)
        {
            continue;
        }

        if (!st.empty())
        {
            cout << "no\n";
        }
        else
        {
            cout << "yes\n";
        }
        
    }

    return 0;
}