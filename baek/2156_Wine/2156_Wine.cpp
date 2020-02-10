#include <iostream>
#include <algorithm>
using namespace std;

long long d[10001];
long long a[10001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }

    d[1] = a[1];
    d[2] = a[1] + a[2];
    for (int i = 3; i <= n; ++i)
    {
        d[i] = max({d[i - 1], d[i - 2] + a[i], d[i - 3] + a[i - 1] + a[i]});
    }

    cout << d[n] << "\n";
}
