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
    // ������ �������� �׻� �����̹Ƿ�
    num.push_back(stoll(number));

    // �켱������ �ֱ�����
    op_priority[0] = '*';
    op_priority[1] = '+';
    op_priority[2] = '-';

    // permutation�� ����ϱ����� sort�� ���ش�.
    sort(op_priority.begin(), op_priority.end());

    // permutation�� ����ϸ� char�� vector�̾ ������� �����ϴ�.
    do {
        // ������ ����� �ؾ��ϹǷ� ���� ���� �����־�� �Ѵ�.
        vector<char> expression_op = op;
        vector<long long> expression_num = num;

        for (int i = 0; i < op_priority.size(); ++i)
        {
            for (int j = 0; j < expression_op.size(); ++j)
            {
                // ������ �켱������ ���� �����ڰ� ���ö� ����ϸ�
                // �켱������ ����� �����ϴ�.
                if (op_priority[i] == expression_op[j])
                {
                    // erase�� delete�� ���� �ٲ�� �����Ƿ�
                    // op_priority[i]�� ���
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

                    // ����� �ߴٸ� vector�� ���빰�鵵 �ٲپ��־���Ѵ�.
                    // ����� ���ڵ��� vector���� �����.
                    // expression_num�� i + 1�� �����.
                    expression_num.erase(expression_num.begin() + j + 1);
                    // ����� �����ڸ� vector���� �����.
                    expression_op.erase(expression_op.begin() + j);

                    // �ϳ��� ������ �̵��Ͽ����Ƿ�
                    // j�� -1�� ���־���Ѵ�.
                    j -= 1;
                }
            }
        }

        // �ִ밪�� �����ؾ��Ѵ�.
        // erase�� insert�� ���� ��ġ�� ��������� �˼��� ������
        // for���� �� ���Ҵٸ� ��� ������� expression_num�� �����ִ�.
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
