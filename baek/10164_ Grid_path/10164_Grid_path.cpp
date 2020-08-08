#include <iostream>
using namespace std;

int a[16][16];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    int x, y;
    int cnt = 1;
    // �迭�� ��� ���� ��ĭ�� �߰��Ͽ� ��ȭ�Ŀ� ����
    // 0��� 0���� �̵��ϴ� ����� ���� 1�̵ǰ� ���ش�.
    a[0][1] = 1;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            a[i][j] = a[i - 1][j] + a[i][j - 1];
            if (k == cnt)
            {
                x = i;
                y = j;
            }
            cnt += 1;
        }
    }

    if (k == 0)
    {
        cout << a[n][m] << "\n";
    }
    else
    {
        // 1���� ���������Ƿ�
        int nx = n - x + 1;
        int ny = m - y + 1;

        // ���������� ĭ�� ���� ���� ����� ���� �迭�� ����Ǿ������Ƿ�
        // O ������ ����� �� * O���� (n, m) ������ ����� �� = O�� ���İ��� ����� ��
        // nx, ny�� O���� (n, m) ������ �簢���� ������ ��ǥ�̹Ƿ�
        // ũ�⸦ ���ؼ� ����� ���� �� �� �ִ�.
        // e.g. nx = 2, ny = 3�ϰ�� a[2][3] �� ����� ���� ����!
        cout << a[x][y] * a[nx][ny] << "\n";
    }
    

    return 0;
}
