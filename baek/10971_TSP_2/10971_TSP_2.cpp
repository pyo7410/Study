#include <iostream>
#include <vector>
#include <algorithm>
#define INF 2147483647
using namespace std;

int a[10][10];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int n, sum;
    int ans = INF;
    bool check;
    cin >> n;

    vector<int> d(n); // 순열을 사용하기 위함
    
    for (int i = 0; i < n; ++i)
    {
        d[i] = i;

        for (int j = 0; j < n; ++j)
        {
            cin >> a[i][j];
        }
    }

    do
    {
        check = true;
        sum = 0;

        for (int i = 0; i < n - 1; ++i) // n - 1은 마지막에 if 에서 처리
        {
            if (a[d[i]][d[i + 1]] == 0)
            {
                check = false;
            }
            else
            {
                sum += a[d[i]][d[i + 1]];
            }
        }
        if (check && a[d[n - 1]][d[0]] != 0)
        {
            sum += a[d[n - 1]][d[0]];
            if (ans > sum)
            {
                ans = sum;
            }
        }

    } while (next_permutation(d.begin(), d.end()));

    cout << ans << "\n";
    
    return 0;
}