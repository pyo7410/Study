#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int tc;
    cin >> tc;
    for (int test_case = 1; test_case <= tc; ++test_case)
    {
        int n;
        int x[10];
        int weight[10];

        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
        {
            scanf("%d", &x[i]);
        }
        for (int i = 0; i < n; ++i)
        {
            scanf("%d", &weight[i]);
        }

        printf("#%d", test_case);

        for (int i = 0; i < n - 1; ++i)
        {
            double mid;
            double left = x[i];
            double right = x[i + 1];
    
            for (int k = 0; k < 50; ++k) 
            {
                mid = (left + right) / 2;

                double sum = 0;

                // 모든 자성체가 범위가 된다!
                for (int j = 0; j <= i; ++j)
                {
                    sum += weight[j] / ((mid - x[j]) * (mid - x[j]));
                }
                for (int j = i + 1; j < n; ++j)
                {
                    sum -= weight[j] / ((mid- x[j]) * (mid- x[j]));
                }

                if (sum > 0)
                {
                    left = mid;
                }
                else
                {
                    right = mid;
                }
            }
            printf(" %.10lf", mid);
        }
        printf("\n");
    }
    
    return 0;
}
