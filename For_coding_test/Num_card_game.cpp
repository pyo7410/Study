#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> vec(n, vector<int>(m));

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> vec[i][j];
        }
    }

    int answer = *min_element(vec[0].begin(), vec[0].end());

    for (int i = 1; i < n; ++i)
    {
        answer = max(answer, *min_element(vec[i].begin(), vec[i].end()));
    }

    cout << answer << "\n";

    return 0;
}