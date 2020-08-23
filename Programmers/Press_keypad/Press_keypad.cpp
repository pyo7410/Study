#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 0 ~ 9 키패드의 위치를 저장한 배열
int number[10][2] = {{3, 1}, {0, 0}, {0, 1}, {0, 2}, {1, 0}, {1, 1}, {1, 2},
                     {2, 0}, {2, 1}, {2, 2}};

string solution(vector<int> numbers, string hand) 
{
    string answer = "";

    // 현재 위치를 저장하기 위함
    pair<int, int> left_hand = {3, 0};
    pair<int, int> right_hand = {3, 2};

    for (int i = 0; i < numbers.size(); ++i)
    {
        int next_num = numbers[i];

        if (next_num == 1 || next_num == 4 || next_num == 7)
        {
            answer += "L";

            // 왼손 위치 갱신
            left_hand = {number[next_num][0], number[next_num][1]};
        }
        else if (next_num == 3 || next_num == 6 || next_num == 9)
        {
            answer += "R";

            // 오른손 위치 갱신
            right_hand = {number[next_num][0], number[next_num][1]};
        }
        else
        {
            // 왼손과 오른손의 거리를 저장
            int left_dist = abs(left_hand.first - number[next_num][0]) + abs(left_hand.second - number[next_num][1]);
            int right_dist = abs(right_hand.first - number[next_num][0]) + abs(right_hand.second - number[next_num][1]);

            // 왼손이 가까우면
            if  (left_dist < right_dist)
            {
                answer += "L";

                // 왼손 위치 갱신
                left_hand = {number[next_num][0], number[next_num][1]};
            }
            else if (right_dist < left_dist) // 오른손이 가까우면
            {
                answer += "R";

                // 오른손 위치 갱신
                right_hand = {number[next_num][0], number[next_num][1]};
            }
            else if (right_dist == left_dist) // 두 손의 거리가 같다면
            {
                if (hand == "right") // 오른손 잡이면
                {
                    answer += "R";

                    // 오른손 위치 갱신
                    right_hand = {number[next_num][0], number[next_num][1]};
                }
                else if (hand == "left") // 왼손 잡이면
                {
                    answer += "L";

                    // 왼손 위치 갱신
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
