#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int row, col;
vector<string> combination;

bool cmp(string a, string b)
{
    return a.length() < b.length();
}

void comb(int k, string tmp) 
{
    for (int i = k; i < col; i++) 
    {
        tmp += to_string(i);
        combination.push_back(tmp);
        comb(i + 1, tmp);
        // temp에서 추가된 글씨를 빼고 원래 temp로 만들어
        // 재귀를 할 수 있게 해준다.
        tmp = tmp.substr(0, tmp.length() - 1);
    }
}

bool isCandidateKey(vector<vector<string>> relation, string combination)
{
    int len = combination.length();
    map<string, bool> m;
    for (int i = 0; i < row; ++i)
    {
        string temp = "";
        for (int j = 0; j < len; ++j)
        {
            int jj = combination[j] - '0';
            temp += relation[i][jj];
        }

        // 해당 값이 있다면 후보키가 될수없으므로
        if (m[temp])
        {
            // false 반환
            return false;
        }
        else // 해당 값이 없다면 후보키가 될 수 있기때문에
        {
            // map에 추가하고 다른 값들도 중복이 없는지 검사
            m[temp] = true;
        }
    }

    return true;
}

int solution(vector<vector<string>> relation) {
    int answer = 0;

    row = relation.size();
    col = relation[0].size();

    // relation으로 만들 수 있는 모든 조합을 만든다.
    string temp;
    for (int i = 0; i < col; ++i)
    {
        temp = "";
        for (int j = i; j < col; ++j)
        {
            temp += to_string(j);
            combination.push_back(temp);
        }
    }

    // 모든 조합을 만들어 준다.
    comb(0, "");
    // 최소성이 있으므로 가장 길이가 짧은 문자열부터 검사하면 된다.
    sort(combination.begin(), combination.end(), cmp);

    for (int i = 0; i < combination.size(); ++i)
    {
        if (isCandidateKey(relation, combination[i]))
        {
            string temp = combination[i];

            // 최소성을 만들기 위해 조합의 길이가 가장 긴 맨 뒤부터
            // 해당 조합으로 이루어진 후보키가 포함되 있는지 검사한다.
            for (int j = combination.size() - 1; j >= i; j--)
            {
               if (includes(combination[j].begin(), combination[j].end(), temp.begin(), temp.end()))
               {
                   // 최소성에 위배되므로 지워준다.
                   combination.erase(combination.begin() + j);;
               }
            }

            // 기존의 i 위치에서 다시 검사하여
            // 혹시 i 가 지워져 뒤에 값이 i에 왔을경우를 방지한다.
            i--;

            // 후보키 이므로 +1
            answer++;
        }
    }

    return answer;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<string>> relation(n, vector<string>(m));

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> relation[i][j];
        }
    }

    cout << solution(relation) << "\n";

    return 0;
}