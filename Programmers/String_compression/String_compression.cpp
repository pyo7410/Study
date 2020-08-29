#include <iostream>
#include <string>
#include <vector>
#define MAX 987654321;
using namespace std;

int solution(string s)
{
    int answer = 0;
    int min = MAX;
    int len_s = s.length();
    vector<pair<string, int>> vec;

    // ���̰� 1�� ���ڿ��� �Է��� ���
    if (len_s == 1)
    {
        return 1;
    }

    // ���ڿ��� ���� �տ��� ���� ������ ���̸�ŭ �߶���Ѵ�.
    // ��, �ִ� len / 2 ��ŭ�� �ڸ� �� �ִ�.

    // i -> ������ ���ڿ��� ��
    for (int i = 1; i <= len_s / 2; ++i)
    {
        
        // �ʱ� ���� �־��ش�.
        vec.push_back({s.substr(0, i), 1});

        // j -> ��ü ���ڿ�
        for (int j = i; j < len_s; j += i)
        {
            string temp = s.substr(j, i);

            // ���� ������ �־��� ���ڿ���
            // �ٸ��ٸ�
            if (vec.back().first != temp)
            {
                vec.push_back({temp, 1});
            }
            else // ���ٸ�
            {
                vec.back().second += 1;   
            }
        }

        // ���� ���ڿ� ����
        string comp_str = "";
        for (int j = 0; j < vec.size(); ++j)
        {
            // ���ڿ��� �ѹ��� ������ ���
            if (vec[j].second == 1)
            {
                comp_str += vec[j].first;
            }
            else // ���ڿ��� ������ ������ ���
            {
                comp_str += (to_string(vec[j].second) + vec[j].first);
            }
        }

        int len_comp_str = comp_str.length();

        // �ּҰ��̸� �� ����
        if (min > len_comp_str)
        {
            min = len_comp_str;
        }

        // �ٸ� ���ڿ��� ���� �ٽ� �ؾ��ϹǷ� �ʱ�ȭ
        vec.clear();
    }

    answer = min;

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
