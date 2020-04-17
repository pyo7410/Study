#include <iostream>
using namespace std;

int a[8];

/*
void go(int index, int start, int n, int m)
{
    if (index == m)
    {
        for (int i = 0; i < m; ++i)
        {
            cout << a[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = start; i <= n; ++i)
    {
        a[index] = i;
        go(index + 1, i + 1, n ,m);
    }
}
*/

void go(int index, int selected, int n, int m)
{
    if (selected == m)
    {
        for (int i = 0; i < m; ++i)
        {
            cout << a[i] << " ";
        }
        cout << "\n"; 
        return;
    }

    if (index > n)
    {
        return;
    }
    // 수열에 포함, 즉 index를 결과에 추가
    a[selected] = index;
    go(index + 1, selected + 1, n, m);
    // 수열에 미포함, 즉 index를 결과에 추가 안함
    a[selected] = 0;
    go(index + 1, selected, n, m);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    //go(0, 1, n, m);
    go(1, 0, n, m);

}
