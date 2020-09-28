#include <iostream>
#include <algorithm>
using namespace std;

int cards[500001];

bool binarySearch(int target, int len)
{
    int st = 0;
    int en = len - 1;
    
    while (st <= en)
    {
        int mid = (st + en) / 2;

        if (cards[mid] < target)
        {
            st = mid + 1;
        }
        else if (cards[mid] > target)
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

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        cin >> cards[i];
    }

    // 이분탐색은 정렬이 필수!
    sort(cards, cards + n);

    int m;
    cin >> m;

    while (m--)
    {
        int card;
        cin >> card;

        if (binarySearch(card, n))
        {
            cout << "1 ";
        }
        else
        {
            cout << "0 ";
        }
    }
    
    cout << "\n";

    return 0;
}