#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <sstream>
#include <set>
using namespace std;

vector<string> split(string input, char delimiter)
{
    vector<string> result;
    stringstream ss(input);
    string temp;

    while (getline(ss, temp, delimiter))
    {
        result.push_back(temp);
    }

    return result;
}

vector<int> solution(vector<string> operations) {
    vector<int> answer(2);

    multiset<int> s;
    for (int i = 0; i < operations.size(); ++i)
    {
        string op = split(operations[i], ' ')[0];
        int num = stoi(split(operations[i], ' ')[1]);

        if (op == "I")
        {
            s.insert(num);
        }
        else if (op == "D")
        {
            if (num == 1)
            {
                if (!s.empty())
                {
                    s.erase(--s.end());
                }
            }
            else if (num == -1)
            {
                if (!s.empty())
                {
                    s.erase(s.begin());
                }
            }
        }
    }

    if (s.empty())
    {
        answer[0] = 0;
        answer[1] = 0;
    }
    else
    {
        auto iter = s.begin();
        answer[1] = *iter;

        auto riter = s.rbegin();
        answer[0] = *riter;
    }
    
    return answer;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    cin.ignore();
    vector<string> operations(n);
    for (int i = 0; i < n; ++i)
    {
        getline(cin, operations[i]);
    }

    solution(operations);

    return 0;
}