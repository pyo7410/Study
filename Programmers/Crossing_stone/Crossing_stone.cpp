#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// https://covenant.tistory.com/162

bool check (vector<int> stones, int k, int mid)
{
    int cnt = 0;

    for (int i = 0; i < stones.size(); ++i)
    {
        // ���� �ǳ� �ο��� ���� stones[i]�� ���ں��� ū ���
        // ��, stones�� i ��°�� ���� �����ִ� Ƚ���� �� ���� 0�� �Ǿ� ������ ���

        // if else ���� ���� �������� cnt�� +1 �Ǿ� k�� ���ų� Ŀ����.
        if (stones[i] < mid)
        {
            // ������ 0�̵Ǵ� ���� ������ +1 �Ͽ�
            cnt++;

            // 0�� ������ K���� ������ ������ �ȴ�!
            // 0�� �Ǵ� ���� ������
            // k �� ���ų� Ŀ���� �ѹ��� ���ǳʰ� �ǹǷ�
            // mid ������ �ο��� �ǳ� �� �ִٴ� �ǹ��̹Ƿ�
            if (cnt >= k)
            {
                return false;
            }
        }
        else
        {
            cnt = 0;
        }
    }

    return true;
}

int solution(vector<int> stones, int k) {
    int answer = 0;
    
    // �ǳ� �� �ִ� �ο��� �ִ� 2���
    // �ִ� ���Ѵ� ������ stones���� 2����� ���Ƿ�
    int right = *max_element(stones.begin(), stones.end());
    // �ǳ� �� �ִ� �ο��� �ּ� 1��
    int left = 1;

    while (left <= right)
    {
        // ���� �ǳ� �ο� ��
        int mid = (left + right) / 2;
        if (check(stones, k, mid))
        {
            left = mid + 1;
            if (answer < mid)
            {
                answer = mid;
            }
        }
        else
        {
            right = mid - 1;
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

    vector<int> stones(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> stones[i];

    }

    int k;
    cin >> k;

    cout << solution(stones, k) << "\n";
    
    return 0;
}
