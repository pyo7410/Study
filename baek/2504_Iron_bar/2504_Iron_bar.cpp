#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int idx = 0;
    int answer = 0;
    string s;
    cin >> s;

    stack<int> st;
    for (char c : s)
    {
        if (c == '(')
        {
            // 레이저 인지 판단하기 위해 idx를 1씩 증가시키며 저장
            st.push(idx++);
        }
        else
        {
            // '(' 이후 바로 나온 ')' 의 idx 와 1차이가 난다.
            if (idx - st.top() == 1)
            {
                // 레이저 괄호를 빼준다.
                st.pop();

                // 레이저에 잘린 막대기는
                // '(' 바로뒤에 ')' 가 없다면 막대기 이므로
                // 레이저 괄호를 제외한 현재 스택에 들어가있는 괄호의 수가 된다.
                answer += st.size();
            }
            else
            {
                // idx와의 차이가 1이 아니라면
                // 막대기의 끝 부분이므로 잘려진 막대기를 포함한
                // 기존의 '(' 까지 를 pop해서 빼주고
                st.pop();
                // 막대기의 잘린 맨 마지막 부분은 1개 뿐이므로
                // 추가해준다.
                answer += 1;
            }
        }
    }

    cout << answer << "\n";

    return 0;
}