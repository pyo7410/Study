#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
using namespace std;

vector<string> split(string input, char delimeter)
{
    vector<string> result;
    stringstream ss(input);
    string temp;
    
    while (getline(ss, temp, delimeter))
    {
        result.push_back(temp);
    }
    
    return result;
}

string solution(string s) {
    string answer = "";
    
    vector<string> str_vec = split(s, ' ');
    
    for (int i = 0; i < str_vec.size(); ++i)
    {
        for (int j = 0; j < str_vec[i].length(); ++j)
        {
            if (j == 0 && islower(str_vec[i][j]))
            {
                str_vec[i][j] = toupper(str_vec[i][j]);
            }
            else if (j > 0 && isupper(str_vec[i][j]))
            {
                str_vec[i][j] = tolower(str_vec[i][j]);
            }
            
            answer += str_vec[i][j];
        }
        
        if (i < str_vec.size() - 1)
        {
            answer += " ";
        }
    }
    
    // 문자열의 맨 마지막 원소가 공백이라면 공백이 포함되어야 한다.
    if (s.back() == ' ')
    {
        answer += " ";
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

    cout << solution(s) << "\n";

    return 0;
}