#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;

    vector<int> slice_array;
    
    for (int i = 0; i < commands.size(); ++i)
    {
        int st = commands[i][0] - 1;
        int en = commands[i][1];
        int idx = commands[i][2] - 1;
        
        slice_array.assign(array.begin() + st, array.begin() + en);
        
        sort(slice_array.begin(), slice_array.end());
        answer.push_back(slice_array[idx]);

        slice_array.clear();
    }
    
    return answer;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n;
    cin >> m;

    vector<int> array(n);
    vector<vector<int>> commands(m, vector<int>(3));

    for (int i = 0; i < n; ++i)
    {
        cin >> array[i];
    }

    for (int i = 0; i < m; ++i)
    {
        cin >> commands[i][0] >> commands[i][1] >> commands[i][2];
    }

    solution(array, commands);

    return 0;
}