#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(string expression) 
{
    long long answer = 0;
    int len = expression.length();

    vector<char> op;
    vector<char> op_priority(3);
    vector<long long> num;

    string number = "";
    for (int i = 0; i < len; ++i)
    {
        if (isdigit(expression[i]))
        {
            number += expression[i];
        }
        else
        {
            op.push_back(expression[i]);
            num.push_back(stoll(number));
            number = "";
        }
    }
    // 수식의 마지막은 항상 숫자이므로
    num.push_back(stoll(number));

    // 우선순위를 주기위함
    op_priority[0] = '*';
    op_priority[1] = '+';
    op_priority[2] = '-';

    // permutation을 사용하기위해 sort를 해준다.
    sort(op_priority.begin(), op_priority.end());

    // permutation을 사용하면 char형 vector이어도 순서대로 가능하다.
    do {
        // 여러번 계산을 해야하므로 원래 식은 남아있어야 한다.
        vector<char> expression_op = op;
        vector<long long> expression_num = num;

        for (int i = 0; i < op_priority.size(); ++i)
        {
            for (int j = 0; j < expression_op.size(); ++j)
            {
                // 연산자 우선순위와 같은 연산자가 나올때 계산하면
                // 우선적으로 계산이 가능하다.
                if (op_priority[i] == expression_op[j])
                {
                    // erase와 delete로 인해 바뀔수 있으므로
                    // op_priority[i]를 사용
                    if (op_priority[i] == '*')
                    {
                        expression_num[j] = expression_num[j] * expression_num[j + 1];
                    }
                    else if (op_priority[i] == '+')
                    {
                        expression_num[j] = expression_num[j] + expression_num[j + 1];
                    }
                    else if (op_priority[i] == '-')
                    {
                        expression_num[j] = expression_num[j] - expression_num[j + 1];
                    }

                    // 계산을 했다면 vector의 내용물들도 바꾸어주어야한다.
                    // 사용한 숫자들을 vector에서 지운다.
                    // expression_num의 i + 1을 지운다.
                    expression_num.erase(expression_num.begin() + j + 1);
                    // 사용한 연산자를 vector에서 지운다.
                    expression_op.erase(expression_op.begin() + j);

                    // 하나씩 앞으로 이동하였으므로
                    // j도 -1을 해주어야한다.
                    j -= 1;
                }
            }
        }

        // 최대값을 갱신해야한다.
        // erase와 insert로 인해 위치가 어디인지는 알수가 없지만
        // for문을 다 돌았다면 계산 결과값은 expression_num에 남아있다.
        if (answer < abs(expression_num.back()))
        {
            answer = abs(expression_num.back());
        }

    } while (next_permutation(op_priority.begin(), op_priority.end()));

    return answer;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    string s;
    cin >> s;

    cout << solution(s) << endl;
    
    return 0;
}
