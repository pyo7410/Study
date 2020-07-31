#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(string a, string b)
{
    if (a.length() == b.length())
    {
        return a < b;
    }
    else
    {
        return a.length() < b.length();
    }    
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int n;
    cin >> n;

    vector<string> vec(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> vec[i];
    }

    sort(vec.begin(), vec.end(), compare);
    vec.erase(unique(vec.begin(), vec.end()), vec.end());

    string temp = "";
    for (int i = 0; i < vec.size(); ++i)
    {
        cout << vec[i] << "\n";
    }
    
    return 0;
}
