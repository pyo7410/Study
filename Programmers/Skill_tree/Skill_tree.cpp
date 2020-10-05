#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

bool visit[26];

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    
    for (int i = 0; i < skill_trees.size(); ++i)
    {
        memset(visit, false, sizeof(visit));
        bool check = true;
        for (int j = 0; j < skill_trees[i].length(); ++j)
        {
            for (int k = 0; k < skill.length(); ++k)
            {
                if (skill[k] == skill_trees[i][j])
                {
                    if (k == 0)
                    {
                        visit[skill[k] - 'A'] = true;
                        break;
                    }
                    else if (k > 0 && visit[skill[k - 1] - 'A'])
                    {
                        visit[skill[k] - 'A'] = true;
                        break;
                    }
                    else if (k > 0 && !visit[skill[k - 1] - 'A'])
                    {
                        check = false;
                        break;
                    }
                }
            }
            
            if (!check)
            {
                break;
            }
        }
        
        if (!check)
        {
            continue;
        }
        
        answer++;
    }
    
    return answer;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string skill;
    cin >> skill;

    int n;
    cin >> n;

    vector<string> skill_trees(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> skill_trees[i];
    }

    cout << solution(skill, skill_trees) << "\n";

    return 0;
}