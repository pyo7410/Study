#include <iostream>
using namespace std;

bool a[12];

int possible(int c)
{
    if (c == 0) // c가 0일때의 예외 처리
    {
        if (a[0])
        {
            return 0;
        }
        else
        {
            return 1;
        }        
    }

    int len = 0;
    while (c > 0)
    {
        if (a[c % 10]) // 맨 마지막 수가 고장났을때
        {
            return 0;
        }
        len += 1;
        c /= 10; // 맨 마지막 수는 누른것이므로 뺀다
    }
    return len;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int n, m, temp;
    int c, len, press, ans;
    cin >> n >> m;

    while (m--)
    {
        cin >> temp;
        a[temp] = true;
    }

    ans = n - 100; // + 나 - 로만 누르는 경우
    if (ans < 0)
    {
        ans = -ans; // 만약 음수 라면 양수로 바꾸어줌
    }
    for (int i = 0; i <= 1000000; ++i) // 이동할 수 있는 모든 채널로 이동 한 경우의 수 전부
    {
        c = i; // 이동할 채널 C 
        len = possible(c);
        if (len > 0) // 특정 채널로 이동 후 +, - 버튼으로 옮길 경우
        {
            press = c - n;
            if (press < 0)
            {
                press = -press;
            }
            if (ans > len + press) // 첫 채널 100에서 +, - 로만 간 것 보다 특정채널 이동 후 +, -가 작을 경우
            {
                ans = len + press;
            }
        }
    }

    cout << ans << "\n";
}
