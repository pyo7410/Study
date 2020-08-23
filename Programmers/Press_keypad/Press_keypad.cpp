#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 0 ~ 9 Ű�е��� ��ġ�� ������ �迭
int number[10][2] = {{3, 1}, {0, 0}, {0, 1}, {0, 2}, {1, 0}, {1, 1}, {1, 2},
                     {2, 0}, {2, 1}, {2, 2}};

string solution(vector<int> numbers, string hand) 
{
    string answer = "";

    // ���� ��ġ�� �����ϱ� ����
    pair<int, int> left_hand = {3, 0};
    pair<int, int> right_hand = {3, 2};

    for (int i = 0; i < numbers.size(); ++i)
    {
        int next_num = numbers[i];

        if (next_num == 1 || next_num == 4 || next_num == 7)
        {
            answer += "L";

            // �޼� ��ġ ����
            left_hand = {number[next_num][0], number[next_num][1]};
        }
        else if (next_num == 3 || next_num == 6 || next_num == 9)
        {
            answer += "R";

            // ������ ��ġ ����
            right_hand = {number[next_num][0], number[next_num][1]};
        }
        else
        {
            // �޼հ� �������� �Ÿ��� ����
            int left_dist = abs(left_hand.first - number[next_num][0]) + abs(left_hand.second - number[next_num][1]);
            int right_dist = abs(right_hand.first - number[next_num][0]) + abs(right_hand.second - number[next_num][1]);

            // �޼��� ������
            if  (left_dist < right_dist)
            {
                answer += "L";

                // �޼� ��ġ ����
                left_hand = {number[next_num][0], number[next_num][1]};
            }
            else if (right_dist < left_dist) // �������� ������
            {
                answer += "R";

                // ������ ��ġ ����
                right_hand = {number[next_num][0], number[next_num][1]};
            }
            else if (right_dist == left_dist) // �� ���� �Ÿ��� ���ٸ�
            {
                if (hand == "right") // ������ ���̸�
                {
                    answer += "R";

                    // ������ ��ġ ����
                    right_hand = {number[next_num][0], number[next_num][1]};
                }
                else if (hand == "left") // �޼� ���̸�
                {
                    answer += "L";

                    // �޼� ��ġ ����
                    left_hand = {number[next_num][0], number[next_num][1]};
                }
            }
        }
    }

    return answer;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int n;
    cin >> n;

    vector<int> numbers(n);
    string hand;

    for (int i = 0; i < n; ++i)
    {
        cin >> numbers[i];
    }

    cin >> hand;

    cout << solution(numbers, hand) << "\n";
    
    return 0;
}
