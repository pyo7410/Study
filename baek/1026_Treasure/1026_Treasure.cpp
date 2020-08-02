#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool desc(int a, int b)
{
    return a > b;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    vector<int> b(n);
    
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    for (int i = 0; i < n; ++i)
    {
        cin >> b[i];
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), desc);

    int s = 0;
    for (int i = 0; i < n; ++i)
    {
        s += a[i] * b[i];
    }

    cout << s << "\n";
    
    return 0;
}
