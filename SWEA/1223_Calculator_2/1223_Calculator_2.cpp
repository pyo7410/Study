#include <iostream>
#include <string>
#include <stack>
using namespace std;

char priority[256];

int calc(string postfix)
{
    int result;
    int len = postfix.length();

    stack<int> num_stk;
    for (int i = 0; i < len; ++i)
    {
        if (postfix[i] >= 48 && postfix[i] <= 57)
        {
            num_stk.push(postfix[i] - '0');
        }
        else
        {
            int y = num_stk.top();
            num_stk.pop();
            int x = num_stk.top();
            num_stk.pop();

            if (postfix[i] == '+')
            {
                num_stk.push(x + y);
            }
            else if (postfix[i] == '*')
            {
                num_stk.push(x * y);
            }
        }   
    }

    result = num_stk.top();
    num_stk.pop();

    return result;
}

string post(string formula, int len)
{
    string postfix;
    stack<char> op_stk;

    // 우선순위 설정
    priority['*'] = 1;
    
    for (int i = 0; i < len; ++i)
    {
        if (formula[i] >= 48 && formula[i] <= 57) // 숫자일 경우
        {
            postfix += formula[i];
        }
        else // 연산자일 경우
        {
            if (!op_stk.empty())
            {
                while (priority[op_stk.top()] >= priority[formula[i]])
                {
                    postfix += op_stk.top();
                    op_stk.pop();

                    // stack이 비어버리면 while 조건문에서 검사를 진행할 수 없어 오류
                    if (op_stk.empty())
                    {
                        break;
                    }
                }
            }
            op_stk.push(formula[i]);
        }
    }

    while (!op_stk.empty())
    {
        postfix += op_stk.top();
        op_stk.pop();
    }

    return postfix;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    for (int test_case = 1; test_case <= 10; ++test_case)
    {
        int len;
        cin >> len;

        string formula;
        cin >> formula;

        string postfix = post(formula, len);    

        cout << "#" << test_case << " " << calc(postfix) << "\n";
    }

    return 0;
}
