#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, ans;
int t[15], p[15]; // 문제에서 ti, pi는 배열의 크기가 아닌 배열안에 들어가는 값의 범위다... 주의!

void go(int day, int sum)
{
    if (day == n)
    {
        ans = max(ans, sum);        
        return;
    }
    if (day > n)
    {
        return;
    }
    go(day + t[day], sum + p[day]); // 상담 O
    go(day + 1, sum);               // 상담 x
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        cin >> t[i] >> p[i];
    }

    go(0, 0);

    cout << ans << "\n";
}
