#include <iostream>
#include <algorithm>
using namespace std;

int building_height[1010];

int main()
{
    for (int cnt = 1; cnt <= 10; ++cnt)
    {
        int len;
        cin >> len;        

        for (int i = 2; i < len + 2; ++i)
        {
            cin >> building_height[i];
        }

        int ans = 0;
        for (int i = 2; i < len + 2; ++i)
        {
            int height = max({building_height[i - 2], building_height[i - 1], building_height[i + 1], building_height[i + 2]});
            
            if (building_height[i] > height)
            {
                ans += building_height[i] - height;
            }
        }

        cout << "#" << cnt << " " << ans << "\n";
    }

    return 0;
}