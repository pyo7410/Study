#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, ans;
int t[15], p[15]; // �������� ti, pi�� �迭�� ũ�Ⱑ �ƴ� �迭�ȿ� ���� ���� ������... ����!

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
    go(day + t[day], sum + p[day]); // ��� O
    go(day + 1, sum);               // ��� x
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
