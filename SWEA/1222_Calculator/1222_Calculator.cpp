#include <iostream>
#include <string>
#include <stack>
using namespace std;

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

            num_stk.push(x + y);
        }    
    }

    result = num_stk.top();
    num_stk.pop();

    return result;
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

        string postfix;
        stack<char> op_stk;
        for (int i = 0; i < len; ++i)
        {
            if (formula[i] >= 48 && formula[i] <= 57) // 숫자일 경우
            {
                postfix += formula[i];
                if (i == len - 1)
                {
                    postfix += op_stk.top();
                    op_stk.pop();
                }
            }
            else // 연산자일 경우
            {
                if (!op_stk.empty())
                {
                    postfix += op_stk.top();
                    op_stk.pop();
                }
                op_stk.push(formula[i]);
            }
        }

        cout << "#" << test_case << " " << calc(postfix) << "\n";
    }

    return 0;
}
