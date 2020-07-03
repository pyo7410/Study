#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> score_cnt(101, 0);

        for (int i = 0; i < 1000; ++i)
        {
            int score;
            cin >> score;

            score_cnt[score] += 1;
        }

        int max = score_cnt[0];
        int ans = 0;
        for (int i = 1; i < 101; ++i)
        {
            if (max <= score_cnt[i])
            {
                max = score_cnt[i];
                ans = i;
            }
        }

        cout << "#" << n << " " << ans << "\n";
    }

    return 0;
}