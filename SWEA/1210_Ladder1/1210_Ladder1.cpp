#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int arr[101][101] = {0, };

    for (int test_case = 1; test_case <= 10; ++test_case)
    {
        int t;
        cin >> t;

        int i, j;
        for (i = 0; i < 100; ++i)
        {
            for (int j = 0; j < 100; ++j)
            {
                cin >> arr[i][j];
            }
        }

        for (j = 0; j < 100; ++j)
        {
            if (arr[99][j] == 2)
            {
                break;
            }
        }

        while (i--)
        {
            if (arr[i][j + 1])
            {
                while (arr[i][j + 1])
                {
                    j += 1;
                }
            }
            else if (arr[i][j - 1])
            {
                while (arr[i][j - 1])
                {
                    j -= 1;
                }
            }
        }

        cout << "#" << test_case << " " << j << "\n";
    }

    return 0;
}
