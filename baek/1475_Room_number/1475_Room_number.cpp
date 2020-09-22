#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    bool isFound;
    string n;
    cin >> n;

    vector<vector<bool>> plastic_set;
    vector<bool> plastic(11, false);

    plastic_set.push_back(plastic);
    for (int i = 0; i < n.length(); ++i)
    {
        isFound = false;
        int j = 0;
        for (; j < plastic_set.size(); ++j)
        {
            if (plastic_set[j][n[i] - '0'])
            {
                if (n[i] - '0' == 6)
                {
                    if (!plastic_set[j][9])
                    {
                        isFound = true;
                        plastic_set[j][9] = true;
                        break;
                    }
                }
                else if (n[i] - '0' == 9)
                {
                    if (!plastic_set[j][6])
                    {
                        isFound = true;
                        plastic_set[j][6] = true;
                        break;
                    }
                }
            }
            else
            {
                isFound = true;
                plastic_set[j][n[i] - '0'] = true;
                break;
            }
        }

        if (!isFound)
        {
            plastic_set.push_back(plastic);

            // for 문에의해 j는 현재 인덱스보다 1이 많다
            plastic_set[j][n[i] - '0'] = true;
        }
    }

    cout << plastic_set.size() << "\n";

    return 0;
}