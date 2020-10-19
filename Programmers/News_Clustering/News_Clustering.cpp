#include <iostream>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    map<string, int> m1;
    map<string, int> m2;

    int len1 = str1.length();
    int len2 = str2.length();

    // ���ڿ��� �빮�ڷ� ��ȯ�����ش�.
    transform(str1.begin(), str1.end(), str1.begin(), ::toupper);
    transform(str2.begin(), str2.end(), str2.begin(), ::toupper);

    // str1���� �� ���ھ� ��� ���ǿ� �´� ���������� �����.
    for (int i = 0; i < len1 - 1; ++i)
    {
        // �� ���ϳ��� ���ĺ��� �ƴ϶�� ���������� �� �� ����.
        if (!isalpha(str1[i]) || !isalpha(str1[i + 1]))
        {
            continue;
        }
        else
        {
            string temp = "";
            temp += str1[i];
            temp += str1[i + 1];
            m1[temp] += 1;
        }
    }

    // str2���� �� ���ھ� ��� ���ǿ� �´� ���������� �����.
    for (int i = 0; i < len2 - 1; ++i)
    {
        // �� ���ϳ��� ���ĺ��� �ƴ϶�� ���������� �� �� ����.
        if (!isalpha(str2[i]) || !isalpha(str2[i + 1]))
        {
            continue;
        }
        else
        {
            string temp = "";
            temp += str2[i];
            temp += str2[i + 1];
            m2[temp] += 1;
        }
    }

    // �����հ� �������� ������ ����
    int a = 0, b = 0;
    // str1 �������� �ݺ�
    // m1, m2�� ���̴� ������ m1���� ���Ե��� �ʾҴٸ� ����
    // �������̹Ƿ� �������� �ʾƵ� �ȴ�.
    for (auto iter : m1)
    {
        // ���� str2�� �������տ� ���Ե� ���ڶ��
        if (!(m2.find(iter.first) == m2.end()))
        {
            // a�� �������̹Ƿ� m1, m2���� �ּҰ��� ����
            a += min(iter.second, m2[iter.first]);
            // b�� �������̹Ƿ� m1, m2���� �ִ밪�� ����
            b += max(iter.second, m2[iter.first]);
            // �ݺ����� ������ ���� ���������� ������ ���� ���������� �������ϹǷ�
            // ���� ���������� ���־���Ѵ�.
            m2.erase(iter.first);
        }
        else
        {
            // str2�� �������տ� ���Ե��� �ʾҴٸ�
            // �������� ������ �� ����, ������ b �� �ش� ���ڿ��� ������ �����ش�.
            b += iter.second;
        }
    }

    // �ݺ����� ���Ͽ� m1������ ��� ���ڿ��� �����Ƿ�
    // m2�� ���� ���ڿ��� �ڵ����� �������� �ǰ� �ȴ�.
    for (auto iter : m2)
    {
        b += iter.second;
    }

    double result;
    // ���� ���ǿ� ���߾� �Ѵ� 0�̶�� 1
    // 65536�� �ٷ� return �ص� �ȴ�.
    if (a == 0 && b == 0)
    {
        result = 1.0;
    }
    else
    {
        result = (double)a / (double)b;
    }

    // ���ϰ� �Ҽ����� ������ ���� int ���� answer�� ����
    answer = result * 65536;

    return answer;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string str1, str2;

    getline(cin, str1);
    getline(cin, str2);

    cout << solution(str1, str2) << "\n";

    return 0;
}