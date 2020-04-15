#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int t;
    int m, n, x, y;

    cin >> t;

    while (t--)
    {        
        bool check = true;
        cin >> m >> n >> x >> y;
        
        // 자기자신과 자기자신을 나머지연산했을때 0이 되지 않게하기위해
        // 먼저 1을 빼고 나머지연산을 하고 나온 결과에 +1을 하면
        // 구하고자하는 값이 정상적이게 나오게된다.
        x -= 1;
        y -= 1;

        for (int i = x; i < (n * m); i += m)
        {
            if (i % n == y)
            {
                cout << i + 1 << "\n";
                check = false;
                break;
            }
        }
        if (check)
        {
            cout << -1 << "\n";
        }
    }
}
