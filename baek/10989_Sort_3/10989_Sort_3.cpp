#include <iostream>
using namespace std;

int a[10001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int n, tmp;
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        cin >> tmp;
        a[tmp]++;
    }

    for (int i = 1; i <= 10000; ++i)
    {
        if (a[i] > 0)
        {
            for (int j = 0; j < a[i]; ++j)
            {
                cout << i << "\n";
            }
        }
    }
}
