#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int a, b;
    int cnt = 0, num = 1, ans = 0;
    cin >> a >> b;

    for (int i = 1; i <= b; ++i)
    {
        if (cnt >= num)
        {
            cnt = 0;
            num += 1;
        }

        if (i >= a)
        {
            ans += num;
        }

        cnt += 1;
    }

    cout << ans << "\n";
    
    return 0;
}
