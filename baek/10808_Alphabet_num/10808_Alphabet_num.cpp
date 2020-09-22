#include <iostream>
#include <vector>
#include <string>
using namespace std;

int a[26];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s;
    cin >> s;

    for (int i = 0; i < s.length(); ++i)
    {
        a[s[i] - 'a'] += 1;
    }

    for (int i = 0; i < 26; ++i)
    {
        cout << a[i] << " ";
    }

    return 0;
}