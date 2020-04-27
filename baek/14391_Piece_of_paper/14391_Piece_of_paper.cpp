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
            scanf("%1d", &a[i][j]); // 1 정수 씩 읽어 오는 것이 중요 cstdio 임포트 필수
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
                if ((k & (1 << idx)) == 0) // 0 인 값 즉 포함되어 있지않다면 가로
                {
                    cur = cur * 10 + a[i][j];
                }
                else // 이어져 있지 않다면 현재의 숫자를 저장
                {
                    sum += cur;
                    cur = 0;
                }                
            }
            sum += cur; // if 에서 끝났을 경우의 값도 더하기 위함.
        }        

        // for문에서 i, j 위치를 바꾸어 주면 세로
        for (int j = 0; j < m; ++j)
        {
            int cur = 0;
            for (int i = 0; i < n; ++i)
            {
                int idx = i * m + j;
                if ((k & (1 << idx)) != 0) // 0이 아닌 값 즉 포함되어 있으면 세로
                {
                    cur = cur * 10 + a[i][j];
                }
                else // 이어져 있지 않다면 현재의 숫자를 저장
                {
                    sum += cur;
                    cur = 0;
                }                
            }
            sum += cur; // if 에서 끝났을 경우의 값도 더하기 위함.
        } 

        ans = max(ans, sum);
    }

    cout << ans << "\n";

    return 0;
}
