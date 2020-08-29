#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

class Trie 
{
private:
    bool finish;    // ������ ���� ǥ��
    int child_cnt;
    Trie *next[26];     // ���ĺ��� 26���� �̹Ƿ�

public:
    Trie() : finish(true), child_cnt(0)
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
        // ���ڿ��� �ߺ��� ���ĺ��� ���� frode, frost �� �ٸ�����
        // insert �Ҷ� ���� +1�� �ϰ� �Ͽ� f, r, o ������ cnt�� 2�� �ȴ�!
        // �� ����ǥ�� ��Ÿ���� ����ǥ�϶��� child_cnt�� ����ǥ�� ��� �ܾ �ȴ�.
        child_cnt += 1;

         // key�� null �̶��
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
    int find(const char* key)
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

// 1 ~ 10000 ���� ������ ���ڿ��� �ֱ� ���� Trie �迭
// ����Ʈ�� �迭�̹Ƿ� * ���̴°� ��������
// �Լ� ������ ���� ũ�� ������ �ֱ⿡
// ���� ������ �ؾ� ������ ũ�Ⱑ �þ��!
Trie *root[10001];
Trie *reverse_root[10001];

// ?�� ���λ��� ��� �ڿ� ���� ���ĺ����� �˻��ϸ� ���� ������.
// ��, ������ ���ڿ��� ������ Trie�� �ϳ� ����� �ȴ�!
vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;

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

        string reverse_word = words[i];
        reverse(reverse_word.begin(), reverse_word.end());
        if (reverse_root[word_len] == NULL)
        {
            reverse_root[word_len] = new Trie();
        }
        reverse_root[word_len]->insert(reverse_word.c_str());
    }

    for (int i = 0; i < queries.size(); ++i)
    {
        string query = queries[i];
        int query_len = query.length();

        // // �ش� ���ڿ� ���̸�ŭ�� �� �ѹ��� ������ �ʾҴٸ�
        if (root[query_len] == NULL)
        {
            answer.push_back(0);
            continue;
        }

        if (reverse_root[query_len] == NULL)
        {
            answer.push_back(0);
            continue;
        }

        // ���� ����ǥ�� ���λ���
        int result = 0;
        if (query[0] == '?')
        {
            string reverse_query = queries[i];
            reverse(reverse_query.begin(), reverse_query.end());
            result = reverse_root[query_len]->find(reverse_query.c_str());
        }
        else
        {
            result = root[query_len]->find(query.c_str());
        }
        
        answer.push_back(result);
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
