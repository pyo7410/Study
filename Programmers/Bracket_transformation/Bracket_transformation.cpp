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

    // 왼쪽 괄호와 오른쪽 괄호의 갯수가 다르면
    // 균형잡힌 괄호 문자열이 아니므로
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
            // 비어있는데 ) 가 나온다는 것은 올바른 문자열이 될 수 없다.
            if (s.empty())
            {
                return false;
            }

            s.pop();
        }
    }

    // 비어있지 않다면
    // 올바른 괄호 문자열이 아니므로
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
        // 문자열 p는 어찌됬든 균형잡인 문자열로 분리된다.
        if (i == (p_len - 1)) 
        {
            for (int j = 0; j <= i; ++j)
            {
                u += p[j];
            }

            break;
        }

        // u는 절대 균형잡힌 괄호 문자열로 다시 분리될 수 없다.
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

    // 올바른 문자열이라면
    if (isCorrect(u))
    {
        u += correctBracket(v);
    }
    else
    {
        string temp = "(";
        temp += correctBracket(v);
        temp += ")";

        // u가 빈 문자열이 아니라면
        // 비어있다면 그대로 진행하면됨
        if (!u.empty())
        {
            // string의 erase는 매개변수가 iterator임을 주의하자!
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
