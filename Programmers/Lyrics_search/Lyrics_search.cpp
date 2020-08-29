#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <unordered_map>
using namespace std;

class Trie
{
private:
    bool finish; // ������ ���� ǥ��
    int child_cnt;
    Trie *next[26]; // ���ĺ��� 26���� �̹Ƿ�

public:
    Trie() : finish(true), child_cnt(0)
    {
        memset(next, 0, sizeof(next));
    }

    ~Trie()
    {
        for (int i = 0; i < 26; ++i)
        {
            delete next[i];
        }
    }

    void insert(const char *key)
    {
        // key�� null �̶��
        child_cnt += 1;

        if (*key == '\0')
        {
            // ���ڿ��� ������ ���������� ǥ��
            finish = true;
        }
        else
        {
            int curr = *key - 'a'; // ���ĺ� �ҹ����� ��ġ�� ��ȯ

            // �ش� ��ġ�� ����ٸ�
            if (next[curr] == NULL)
            {
                // �ش� ���ĺ� ��ġ�� �����Ҵ�
                next[curr] = new Trie();
            }

            next[curr]->insert(key + 1);
        }
    }

    // ����ǥ �ϰ�� �ڽ��� ������ �����ϸ� �ȴ�.
    // ����ǥ�� ������ �Ѱ� �̻��� �� �����Ƿ�
    // ������ �������� ����ǥ�� �ǰ� �ȴ�.
    int find(const char *key)
    {
        // ���� ���� ���ڰ� ����ǥ ���
        if (*key == '?')
        {
            return child_cnt;
        }

        int curr = *key - 'a';
        if (next[curr] == NULL) // ���� ���� ��ġ�� ����ִٸ�
        {
            return 0;
        }

        return next[curr]->find(key + 1);
    }
};

// ?�� ���λ��� ��� �ڿ� ���� ���ĺ����� �˻��ϸ� ���� ������.
// ��, ������ ���ڿ��� ������ Trie�� �ϳ� ����� �ȴ�!
vector<int> solution(vector<string> words, vector<string> queries)
{
    vector<int> answer;

    // 1 ~ 10000 ���� ������ ���ڿ��� �ֱ� ���� Trie �迭
    // ����Ʈ�� �迭�̹Ƿ� * ���̴°� ��������
    Trie *root[10100];
    Trie *reverse_root[10100];

    // words�� ������ Trie�� �ִ´�.
    for (int i = 0; i < words.size(); ++i)
    {
        string word = words[i];
        int word_len = word.length();

        // �ش� ���ڿ� ���̸�ŭ�� �� �ѹ��� ������ �ʾҴٸ�
        if (root[word_len] == NULL)
        {
            root[word_len] = new Trie();
        }
        root[word_len]->insert(word.c_str());

        reverse(word.begin(), word.end());
        if (reverse_root[word_len] == NULL)
        {
            reverse_root[word_len] = new Trie();
        }
        reverse_root[word_len]->insert(word.c_str());
    }

    // �˻��� �ߺ� ����
    unordered_map<string, int> m;
    for (int i = 0; i < queries.size(); ++i)
    {
        string query = queries[i];
        int query_len = query.length();

        if (m.count(query) == 0)
        {
            int result = 0;

            // ���� ����ǥ�� ���λ���
            if (query[0] == '?')
            {
                if (reverse_root[query_len] == NULL)
                {
                    answer.push_back(0);
                    continue;
                }
                else
                {
                    reverse(query.begin(), query.end());

                    result = reverse_root[query_len]->find(query.c_str());
                }
            }
            else
            {
                if (root[query_len] == NULL)
                {
                    answer.push_back(0);
                    continue;
                }
                else
                {
                    result = root[query_len]->find(query.c_str());
                }
            }
            m[query] = result;

            answer.push_back(result);
        }
        else
        {
            answer.push_back(m[query]);
        }
    }

    return answer;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<string> words(n);
    vector<string> queries(m);

    for (int i = 0; i < n; ++i)
    {
        cin >> words[i];
    }

    for (int i = 0; i < m; ++i)
    {
        cin >> queries[i];
    }

    vector<int> v;
    v = solution(words, queries);

    for (int i = 0; i < v.size(); ++i)
    {
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}
