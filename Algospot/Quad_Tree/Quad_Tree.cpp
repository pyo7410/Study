#include <iostream>
#include <string>
using namespace std;

string reverse(string::iterator& it)
{
    char head = *it;

    // it의 값은 reference 이므로 계속해서 증가한다.
    ++it;

    if (head == 'b' || head == 'w')
    {
        // head를 1번 저장한다는 의미
        // 즉, head 한글자를 반환
        return string(1, head);
    }

    // 1 / 4 등분한 그래프에서 각각 뒤집은 상태를 구한다.
    string upperLeft = reverse(it);
    string upperRight = reverse(it);
    string lowerLeft = reverse(it);
    string lowerRight = reverse(it);

    // 각각 위와 아래조각들의 위치를 바꾼다.
    return "x" + lowerLeft + lowerRight + upperLeft + upperRight;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int c;
    cin >> c;

    while (c--)
    {
        string s;
        cin >> s;

        string::iterator iter = s.begin();

        cout << reverse(iter) << "\n";
    }

    return 0;
}