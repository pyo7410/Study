#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

bool isbalanced(string p)
{
    int p_len = p.length();
    int l_cnt = 0, r_cnt = 0;

    for (int i = 0; i < p_len; ++i)
    {
        if (p[i] == '(')
        {
            l_cnt += 1;
        }
        else if (p[i] == ')')
        {
            r_cnt += 1;
        }
    }

    // ?? ??? ??? ??? ??? ???
    // ???? ?? ???? ????
    if (l_cnt != r_cnt)
    {
        return false;
    }

    return true;
}

bool isCorrect(string u)
{
    int u_len = u.length();
    stack<char> s;

    for (int i = 0; i < u_len; ++i)
    {
        if (u[i] == '(')
        {
            s.push('(');
        }
        else if (u[i] == ')')
        {
            // ????? ) ? ???? ?? ??? ???? ? ? ??.
            if (s.empty())
            {
                return false;
            }

            s.pop();
        }
    }

    // ???? ???
    // ??? ?? ???? ????
    if (!s.empty())
    {
        return false;
    }

    return true;
}

string correctBracket(string p)
{
    int left_cnt = 0, right_cnt = 0;
    int p_len = p.length();

    if (p.empty())
    {
        return p;
    }

    string u = "", v = "";

    if (p[0] == '(')
    {
        left_cnt += 1;
    }
    else if (p[0] == ')')
    {
        right_cnt += 1;
    }

    for (int i = 1; i < p_len; ++i)
    {
        // ??? p? ???? ???? ???? ????.
        if (i == (p_len - 1)) 
        {
            for (int j = 0; j <= i; ++j)
            {
                u += p[j];
            }

            break;
        }

        // u? ?? ???? ?? ???? ?? ??? ? ??.
        if (left_cnt == right_cnt)
        {
            for (int j = 0; j < i; ++j)
            {
                u += p[j];
            }

            for (int j = i; j < p_len; ++j)
            {
                v += p[j];
            }

            break;
        }
        else if (p[i] == '(')
        {
            left_cnt += 1;
        }
        else if (p[i] == ')')
        {
            right_cnt += 1;
        }
    }

    // ??? ??????
    if (isCorrect(u))
    {
        u += correctBracket(v);
    }
    else
    {
        string temp = "(";
        temp += correctBracket(v);
        temp += ")";

        // u? ? ???? ????
        // ????? ??? ?????
        if (!u.empty())
        {
            // string? erase? ????? iterator?? ????!
            u.erase(u.begin());
            u.erase(u.end() - 1);
        }        

        for (int i = 0; i < u.length(); ++i)
        {
            if (u[i] == '(')
            {
                u[i] = ')';
            }
            else if (u[i] == ')')
            {
                u[i] = '(';
            }
        }

        temp += u;

        return temp;
    }

    return u;
}

string solution(string p)
{
    string answer = "";

    if (p.empty())
    {
        return p;
    }

    if (!isbalanced(p))
    {
        return p;
    }
    else
    {
        answer = correctBracket(p);
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
    solution(s);

    return 0;
}