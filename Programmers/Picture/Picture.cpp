#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) 
{
    int answer = 0;
    vector<char> friends = {'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T'};
    vector<char>::iterator iter;

    do {

        bool check = true;

        for (int i = 0; i < n; ++i)
        {
            char friend1 = data[i][0];
            char friend2 = data[i][2];
            char op = data[i][3];

            // 숫자로 바꾸어 주어야 함을 잊지말자
            int space = data[i][4] - '0';

            iter = find(friends.begin(), friends.end(), friend1);
            int idx1 = distance(friends.begin(), iter);

            iter = find(friends.begin(), friends.end(), friend2);
            int idx2 = distance(friends.begin(), iter);

            // 두 친구를 제외한 두 프렌즈 사이에 있는 다른 프렌즈의 수이므로 -1 을 해주어야 한다.
            int realDistance;
            if (idx1 > idx2)
            {
                realDistance = idx1 - idx2 - 1;
            }
            else
            {
                realDistance = idx2 - idx1 - 1;
            }
            
            if ((op == '=' && realDistance != space) || (op == '<' && realDistance >= space) || (op == '>' && realDistance <= space))
            {
                // 조건에 위배되므로
                check = false;
                break;
            }
        }

        if (check)
        {
            answer++;
        }

    } while (next_permutation(friends.begin(), friends.end()));

    return answer;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    vector<string> data(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> data[i];
    }

    cout << solution(n, data) << "\n";
 
    return 0;
}