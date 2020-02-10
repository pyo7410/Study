#include <iostream>
using namespace std;

#define mod 9901

int d[100001];
int s[100001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int n;
    cin >> n;

    d[0] = 1;
    s[0] = 1;
    d[1] = 2;
    s[1] = d[0] + d[1];
    for (int i = 2; i <= n; ++i)
    {
        d[i] = (d[i - 1] + 2 * s[i - 2]) % mod;
        s[i] = (d[i] + s[i - 1]) % mod;
    }

    cout << s[n] << "\n";
}
