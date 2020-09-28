#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int a[100001];

bool binarySearch(int target, int len)
{
    int st = 0;
    int en = len - 1;

    while (st <= en)
    {
        int mid = (st + en) / 2;

        if (a[mid] < target)
        {
            st = mid + 1;
        }
        else if (a[mid] > target)
        {
            en = mid - 1;
        }
        else
        {
            return true;
        }
    }

    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    // 이진탐색은 무조건 정렬이 되어있어야 한다.
    sort(a, a + n);

    cin >> m;
    while (m--)
    {
        int num;
        cin >> num;

        if (binarySearch(num, n))
        {
            cout << "1\n";
        }
        else
        {
            cout << "0\n";
        }
    }    

    return 0;
}