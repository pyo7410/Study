#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int nick_cnt;
string ans;

class Trie
{
private:
    bool finish;
    int cnt;        // �г��� ���� count;
    Trie *next[26]; // ���ĺ��� 26�� �̹Ƿ�

public:
    Trie() : finish(false)
    {
        cnt = 0;
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

    void insert(const char *key)
    {
        if (*key == '\0')
        {
            nick_cnt = ++cnt;
            finish = true;
        }
        else
        {
            int curr = *key - 'a';

            if (next[curr] == NULL)
            {
                next[curr] = new Trie();
            }

            next[curr]->insert(key + 1);
        }
    }

    Trie *find(const char *key)
    {
        if (*key == '\0')
        {
            nick_cnt = ++cnt;

            if (finish)
            {
                return this;
            }

            return NULL;
        }

        ans += *key;
        int curr = *key - 'a';

        if (next[curr] == NULL)
        {
            return NULL;
        }

        return next[curr]->find(key + 1);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    string input;
    Trie *root = new Trie();

    while (n--)
    {
        cin >> input;

        ans = "";
        nick_cnt = -1;

        if (!root->find(input.c_str()))
        {
            // ��, �ѹ��� �г����� ������ ���� ���ٸ�
            // ���θ��� �г����� ������ Trie�� ����Ǿ��ִ� �г��Ӻ��� �����
            // if (next[curr] == NULL)�� ���� NULL�� Return �ǹǷ�
            // Trie �˰����� ���� ã�� ���ߴٰ� ���´�!

            // ���� ���θ��� �г����� ������ Trie�� ����Ǿ��ִ� �г��Ӻ��� ª��
            // ���λ簡 �Ǵ��� ������ ���� �г����� �ƴϹǷ� Trie �˰������� if (*key == '\0')�� ���� NULL ���� ���ϵǾ�
            // ã�� ���ߴٰ� ���´�!

            // ã������ �г����� insert�� ���ش�
            if (nick_cnt == -1)
            {
                root->insert(input.c_str());
            }
        }

        // �г����� �ѹ��� �����ٸ� �״��
        if (nick_cnt == 1)
        {
            cout << ans << "\n";
        }
        else // �г����� �ѹ� �̻� �����ٸ� ���϶� ���� �г��� �ڿ� +1 �� ���ڸ� �ٿ� ���
        {
            cout << ans + to_string(nick_cnt) << "\n";
        }
    }

    return 0;
}