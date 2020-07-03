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
            if (building_height[i] > building_height[i - 1] && building_height[i] > building_height[i - 2])
            {
                if (building_height[i] > building_height[i + 1] && building_height[i] > building_height[i + 2])
                {
                    int height = building_height[i] - max({building_height[i - 2], building_height[i - 1], building_height[i + 1], building_height[i + 2]});
 
                    ans = ans + height;
                }
            }
        }
 
        cout << "#" << cnt << " " << ans << "\n";
    }
 
    return 0;
}