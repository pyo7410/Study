#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

class Trie {
private:
    bool finish; // ������ ���� ǥ��
    Trie* next[26]; // ���ĺ��� 26 ���� �̹Ƿ�

public:
    Trie() : finish(false) 
    {
        memset(next, 0, sizeof(next));
    }

    ~Trie()
    {
        for (int i = 0; i < 26; ++i)
        {
            if (next[i])
            {
                delete next[i];
            }
        }
    }

    void insert(const char* key)
    {
        // key�� null�̶��
        if (*key == '\0')
        {
            finish = true; // ���ڿ��� ������ �������� ǥ��
        }
        else
        {
            int curr = *key - '0'; // ���� ��ġ�� ��ȯ (��Ȳ�� �°� �빮�ڴ� 'A', �ҹ��ڴ� 'a'�� ��ü)

            if (next[curr] == NULL) // �ش� ��ġ�� ����ִٸ�
            {
                next[curr] = new Trie(); // �����Ҵ�
            }

            next[curr]->insert(key + 1); // key + 1�� �Ͽ� ���� ���ڸ� ����
        }
    }

    Trie* find(const char* key)
    {
        if (*key == '\0') // key�� null�̶�� ��, ���ڿ����� ������ ���ڶ��
        {
            return this; // 0�� �ƴ� ���� ����
        }

        int curr = *key - '0'; // ���� ��ġ�� ��ȯ (��Ȳ�� �°� �빮�ڴ� 'A', �ҹ��ڴ� 'a'�� ��ü)

        if (next[curr] == NULL) // �ش� ��ġ�� ����ִٸ�
        {
            return NULL; // ã�� ���� �����Ƿ� NULL ��ȯ
        }

        return next[curr]->find(key + 1); // key + 1�� �Ͽ� ���� ���ڵ� �ִ��� �˻�
    }
};

bool comp(string s1, string s2)
{
    return s1.length() > s2.length();
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<string> vec_str(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> vec_str[i];
        }

        sort(vec_str.begin(), vec_str.end(), comp);
        Trie *root = new Trie();

        root->insert(vec_str[0].c_str());

        string ans = "YES";

        for (int i = 1; i < n; ++i)
        {
            if (root->find(vec_str[i].c_str()))
            {
                ans = "NO";
                break;
            }
            root->insert(vec_str[i].c_str());
        }

        cout << ans << "\n";
    }
    
    return 0;
}
