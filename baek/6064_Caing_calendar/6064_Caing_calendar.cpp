#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int t;
    int m, n, x, y;

    cin >> t;

    while (t--)
    {        
        bool check = true;
        cin >> m >> n >> x >> y;
        
        // �ڱ��ڽŰ� �ڱ��ڽ��� ���������������� 0�� ���� �ʰ��ϱ�����
        // ���� 1�� ���� ������������ �ϰ� ���� ����� +1�� �ϸ�
        // ���ϰ����ϴ� ���� �������̰� �����Եȴ�.
        x -= 1;
        y -= 1;

        for (int i = x; i < (n * m); i += m)
        {
            if (i % n == y)
            {
                cout << i + 1 << "\n";
                check = false;
                break;
            }
        }
        if (check)
        {
            cout << -1 << "\n";
        }
    }
}
