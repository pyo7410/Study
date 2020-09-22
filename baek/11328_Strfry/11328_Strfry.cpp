#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    string tc;
    string strfry_tc;
    while (n--)
    {
        cin >> tc;
        cin >> strfry_tc;

        sort(tc.begin(), tc.end());
        sort(strfry_tc.begin(), strfry_tc.end());

        bool isImpossible = false;
        for (int i = 0; i < tc.length(); ++i)
        {
            if (tc[i] != strfry_tc[i])
            {
                isImpossible = true;
                cout << "Impossible\n";
                break;
            }
        }

        if (!isImpossible)
        {
            cout << "Possible\n";
        }
    }

    return 0;
}