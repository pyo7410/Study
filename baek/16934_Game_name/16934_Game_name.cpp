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
    int cnt;
    Trie *next[26]; // 알파벳이 26개 이므로

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

        if (finish && next[curr] == NULL)
        {
            return NULL;
        }

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
            if (nick_cnt == -1)
            {
                root->insert(input.c_str());
            }
        }

        if (nick_cnt == 1)
        {
            cout << ans << "\n";
        }
        else
        {
            cout << ans + to_string(nick_cnt) << "\n";
        }
    }

    return 0;
}