#include <iostream>
using namespace std;

bool a[12];

int possible(int c)
{
    if (c == 0) // c�� 0�϶��� ���� ó��
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
        if (a[c % 10]) // �� ������ ���� ���峵����
        {
            return 0;
        }
        len += 1;
        c /= 10; // �� ������ ���� �������̹Ƿ� ����
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

    ans = n - 100; // + �� - �θ� ������ ���
    if (ans < 0)
    {
        ans = -ans; // ���� ���� ��� ����� �ٲپ���
    }
    for (int i = 0; i <= 1000000; ++i) // �̵��� �� �ִ� ��� ä�η� �̵� �� ����� �� ����
    {
        c = i; // �̵��� ä�� C 
        len = possible(c);
        if (len > 0) // Ư�� ä�η� �̵� �� +, - ��ư���� �ű� ���
        {
            press = c - n;
            if (press < 0)
            {
                press = -press;
            }
            if (ans > len + press) // ù ä�� 100���� +, - �θ� �� �� ���� Ư��ä�� �̵� �� +, -�� ���� ���
            {
                ans = len + press;
            }
        }
    }

    cout << ans << "\n";
}
