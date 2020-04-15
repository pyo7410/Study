#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    long long ans = 0;
    int n, end;
    cin >> n;

    for (int start = 1, len = 1; start <= n; start *= 10, len++)
    {
        end = start * 10 - 1;
        if (end > n)
        {
            end = n;
        }
        ans += (long long)(end - start + 1) * len;
    }

    cout << ans << "\n";
}
