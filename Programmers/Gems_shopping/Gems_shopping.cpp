#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#define MAX 987654321;
using namespace std;

vector<int> solution(vector<string> gems)
{
    vector<int> answer;

    // ��ü ������ ���� map
    unordered_map<string, int> total_gem;
    // ������ ������ ���� map
    unordered_map<string, int> buy_gems;

    int gems_size = gems.size();
    for (int i = 0; i < gems_size; ++i)
    {
        total_gem[gems[i]] += 1;
    }

    int total_gems_cnt = total_gem.size();

    // ���������� �������� ����� ����
    // left -> ��� ������ ���ԵǸ� �ּұ����� ���� ã�� ���� +1�� �����ذ���.
    // right -> ��� ������ ���ԾȵǸ� ���ο� ������ �߰��� ��� ������ �����Ҷ����� +1�� �����ذ���.
    // ���� �ּҹ����� �ƴ� �ִ빮����� left�� ���� �ʿ䰡 ���� ��...
    // ���ʿ� �ִ밡 ���� �ȵǱ�� �Ѵ�. gems�� ��ü������ �ִ��� �� �̹Ƿ�
    int left = 0, right = 0;

    // �ʱ�ȭ
    answer.push_back(left);
    answer.push_back(right);
    buy_gems[gems[0]] += 1;

    int min = MAX;
    while (left < gems_size && right < gems_size)
    {
        // ������ ������ ��ü ������ ���ԵǾ��ִٸ�
        if (buy_gems.size() == total_gems_cnt)
        {
            int gem_cnt = 0;

            // �������� ��ü �󵵼��� ���Ѵ�.
            for (auto iter = buy_gems.begin(); iter != buy_gems.end(); ++iter)
            {
                gem_cnt += iter->second;
            }

            // �ּ� ������ ���ϴ� ���̹Ƿ�
            if (min > gem_cnt)
            {
                min = gem_cnt;
                answer[0] = left + 1;
                answer[1] = right + 1;
            }

            // left�� ��ġ�� +1 �ϱ����ؼ� �켱 ���� left ���� ������ �󵵼��� 1���־���Ѵ�.
            buy_gems[gems[left]] -= 1;
            // ���� ������ �󵵼��� 0�̶�� map���� ���־�� �Ѵ�.
            // �ȱ׷���� if (buy_gems.size() == total_gems_cnt) ���ǿ� ��� �ɸ��ԵǾ�
            // �̻��� ���� ��µȴ�.
            if (buy_gems[gems[left]] == 0)
            {
                buy_gems.erase(gems[left]);
            }
            left += 1;
        }
        else // ���� ������ ������ ��ü������ ���ԵǾ����� �ʴٸ�
        {
            right += 1;

            if (right < gems_size)
            {
                // �̵��� right�� ���� �󵵼��� �߰����ش�.
                buy_gems[gems[right]] += 1;
            }
        }
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
    vector<string> s(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> s[i];
    }

    vector<int> ans = solution(s);

    return 0;
}
