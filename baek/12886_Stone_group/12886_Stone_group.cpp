#include <iostream>
using namespace std;

bool check[1501][1501]; // A, B, C ���� �ִ밡 500�̹Ƿ� �ִ밡 �ɼ��ִ� ���� 1500�� �ȴ�.
int sum;

void go(int x, int y)
{
    if (check[x][y])
    {
        return;
    }
    check[x][y] = true;

    // sum�� A, B, C�� ���̹Ƿ� C�� sum - A - B�� �ȴ�.
    // 1500^3�� 1500^2���� ���� �� �ִ�.
    int a[3] = {x, y, sum - x - y};
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (a[i] < a[j])
            {
                // �ᱹ C�� A, B�� ���� �ٲ�� �ǹǷ�
                // A�� �߰��� �� ��ŭ B���� ������ �ȴ�.
                int b[3] = {x, y, sum - x - y};
                b[i] += a[i];
                b[j] -= a[i];
                go(b[0], b[1]);
            }
        }
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int a, b, c;
    cin >> a >> b >> c;

    sum = a + b + c;

    // 3���� ������ ���� ������ ���� ���� ���� ���� ���� ����.
    if (sum % 3 != 0)
    {
        cout << 0 << "\n";
        return 0;
    }

    go(a, b);

    // 3���� ���� ��� ���� ����� sum / 3�� �ȴ�.
    // �� ���� �湮�� �ߴٸ�
    if (check[sum / 3][sum / 3])
    {
        cout << 1 << "\n";
    }
    else
    {
        cout << 0 <<"\n";
    }
    
    
    return 0;
}
