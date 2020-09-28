#include <iostream>
#include <algorithm>
#include <map>
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

    map<int, int> card_cnt;

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        cin >> cards[i];
        card_cnt[cards[i]] += 1;
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
            cout << card_cnt[card] << " ";
        }
        else
        {
            cout << "0 ";
        }
    }
    
    cout << "\n";

    return 0;
}