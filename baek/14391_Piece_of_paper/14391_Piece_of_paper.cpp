#include <iostream>
#include <cstdio>
using namespace std;

int a[4][4];

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            scanf("%1d", &a[i][j]); // 1 ���� �� �о� ���� ���� �߿� cstdio ����Ʈ �ʼ�
        }
    }

    int ans = 0;
    for (int k = 0; k < (1 << (n * m)); ++k)
    {
        int sum = 0;

        for (int i = 0; i < n; ++i)
        {
            int cur = 0;
            for (int j = 0; j < m; ++j)
            {
                int idx = i * m + j;
                if ((k & (1 << idx)) == 0) // 0 �� �� �� ���ԵǾ� �����ʴٸ� ����
                {
                    cur = cur * 10 + a[i][j];
                }
                else // �̾��� ���� �ʴٸ� ������ ���ڸ� ����
                {
                    sum += cur;
                    cur = 0;
                }                
            }
            sum += cur; // if ���� ������ ����� ���� ���ϱ� ����.
        }        

        // for������ i, j ��ġ�� �ٲپ� �ָ� ����
        for (int j = 0; j < m; ++j)
        {
            int cur = 0;
            for (int i = 0; i < n; ++i)
            {
                int idx = i * m + j;
                if ((k & (1 << idx)) != 0) // 0�� �ƴ� �� �� ���ԵǾ� ������ ����
                {
                    cur = cur * 10 + a[i][j];
                }
                else // �̾��� ���� �ʴٸ� ������ ���ڸ� ����
                {
                    sum += cur;
                    cur = 0;
                }                
            }
            sum += cur; // if ���� ������ ����� ���� ���ϱ� ����.
        } 

        ans = max(ans, sum);
    }

    cout << ans << "\n";

    return 0;
}
