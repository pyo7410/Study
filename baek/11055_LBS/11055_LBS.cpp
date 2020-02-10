#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n + 1);
    vector<int> d(n + 1);

    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }

    for (int i = 1; i <= n; ++i)
    {
        d[i] = a[i];
        for (int j = 0; j < i; ++j)
        {
            if (a[i] > a[j] && d[i] < d[j] + a[i])
            {
                d[i] = d[j] + a[i];
            }
        }
    }

    cout << *max_element(d.begin(), d.end()) << "\n";
}
