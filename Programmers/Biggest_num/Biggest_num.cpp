#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool cmp(string a, string b)
{
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    string answer = "";
    
    vector<string> temp;
    
    for (auto num : numbers)
    {
        temp.push_back(to_string(num));
    }
    
    sort(temp.begin(), temp.end(), cmp);

    // numbers에 전부 0일 수 있기에
    // 0이 가장 큰 수 라면
    if (temp[0] == "0")
    {
        return "0";
    }
    
    for (auto num : temp)
    {
        answer += num;
    }
    
    return answer;
}