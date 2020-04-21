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
    int a[10000];
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    if (prev_permutation(a, a + n))
    {
        for (int i = 0; i < n; ++i)
        {
            cout << a[i] << " ";
        }
    }
    else
    {
        cout << "-1";
    }
    
    cout << "\n";

}