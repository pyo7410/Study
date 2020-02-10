#include <iostream>
using namespace std;

int d[100001][3];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int n;
    cin >> n;

    d[1][0] = 1;
    d[1][1] = 1;
    d[1][2] = 1;
    for (int i = 2; i <= n; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (j == 0)
            {
                d[i][j] = (d[i - 1][0] + d[i - 1][1] + d[i - 1][2]) % 9901;
            }
            else if (j == 1)
            {
                d[i][j] = (d[i - 1][0] + d[i - 1][2]) % 9901;
            }
            else
            {
                d[i][j] = (d[i - 1][0] + d[i - 1][1]) % 9901;
            }
        }
    }

    cout << (d[n][0] + d[n][1] + d[n][2]) % 9901 << "\n";
}
