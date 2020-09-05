#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

bool comp(pair<int, int> a, pair<int, int> b)
{
    return a.second > b.second;
}

string preprocessing(string s)
{
    s.erase(s.begin());
    s.erase(s.end() - 1);

    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] == '{' || s[i] == '}')
        {
            s.erase(s.begin() + i);
        }
    }

    return s;
}

vector<int> solution(string s)
{
    vector<int> answer;
    map<int, int> tuple;

    string pre_s = preprocessing(s);
    string num = "";
    for (int i = 0; i < pre_s.size(); ++i)
    {
        // 숫자라면
        if (pre_s[i] > 47 && pre_s[i] < 58)
        {
            num += pre_s[i];
        }
        else
        {
            tuple[stoi(num)] += 1;
            num = "";
        }
    }
    tuple[stoi(num)] += 1;

    vector<pair<int, int>> temp;
    for (map<int, int>::iterator iter = tuple.begin(); iter != tuple.end(); ++iter)
    {
        temp.push_back(make_pair(iter->first, iter->second));
    }

    sort(temp.begin(), temp.end(), comp);

    for (int i = 0; i < temp.size(); ++i)
    {
        answer.push_back(temp[i].first);
    }

    return answer;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    string s;
    cin >> s;

    vector<int> ans = solution(s);

    for (int i = 0; i < ans.size(); ++i)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    
    return 0;
}
