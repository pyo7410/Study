#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(int n) {
    string answer = "";
    
    int num = n;
    int mod;
    
    while (num != 0)
    {
        mod = num % 3;
        num = num / 3;
        
        if (mod == 0)
        {
            answer = "4" + answer;

            // n이 3이면 나눈 나머지는 0이 되고 몫은 1이된다.
            // 만약 나눈 나머지가 0일 때 4를 이어 붙인 후 1을 빼지 않으면 몫은 1이 갱신되며
            // 결국 값은 14가 되고 말 것이다. n이 3일 때는 4가 답이다
            num--;
        }
        else if (mod == 1)
        {
            answer = "1" + answer;
        }
        else
        {
            answer = "2" + answer;
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

    cout << solution(n) << "\n";

    return 0;
}