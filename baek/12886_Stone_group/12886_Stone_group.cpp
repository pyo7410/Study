#include <iostream>
using namespace std;

bool check[1501][1501]; // A, B, C 각각 최대가 500이므로 최대가 될수있는 수는 1500이 된다.
int sum;

void go(int x, int y)
{
    if (check[x][y])
    {
        return;
    }
    check[x][y] = true;

    // sum은 A, B, C의 합이므로 C는 sum - A - B가 된다.
    // 1500^3을 1500^2으로 줄일 수 있다.
    int a[3] = {x, y, sum - x - y};
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (a[i] < a[j])
            {
                // 결국 C는 A, B에 의해 바뀌게 되므로
                // A에 추가한 수 만큼 B에서 빠지게 된다.
                int b[3] = {x, y, sum - x - y};
                b[i] += a[i];
                b[j] -= a[i];
                go(b[0], b[1]);
            }
        }
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int a, b, c;
    cin >> a >> b >> c;

    sum = a + b + c;

    // 3으로 나누어 지지 않으면 돌의 수를 같게 만들 수가 없다.
    if (sum % 3 != 0)
    {
        cout << 0 << "\n";
        return 0;
    }

    go(a, b);

    // 3개의 수가 모두 같은 수라면 sum / 3이 된다.
    // 그 수에 방문을 했다면
    if (check[sum / 3][sum / 3])
    {
        cout << 1 << "\n";
    }
    else
    {
        cout << 0 <<"\n";
    }
    
    
    return 0;
}
