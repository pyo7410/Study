#include <iostream>
using namespace std;

int arr[50][50];
int n, m;

int square()
{
    int max_size = 1;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            for (int k = 1; k < m; ++k)
            {
                if (i + k < n && j + k < m)
                {
                    if (arr[i][j + k] == arr[i][j] && arr[i + k][j] == arr[i][j] && arr[i + k][j + k] == arr[i][j])
                    {
                        int square_size = (k + 1) * (k + 1);

                        if (max_size < square_size)
                        {
                            max_size = square_size;
                        }
                    }
                }
            }
        }
    }

    return max_size;
}

int main()
{
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            scanf("%1d", &arr[i][j]);
        }
    }

    cout << square() << "\n";

    return 0;
}
