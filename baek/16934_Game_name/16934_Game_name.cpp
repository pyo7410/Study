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
    int cnt;        // 닉네임 개수 count;
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
            // 즉, 한번도 닉네임이 생성된 적이 없다면
            // 새로만든 닉네임이 기존에 Trie에 저장되어있던 닉네임보다 길더라도
            // if (next[curr] == NULL)로 인해 NULL이 Return 되므로
            // Trie 알고리즘에 의해 찾지 못했다고 나온다!

            // 또한 새로만든 닉네임이 기존에 Trie에 저장되어있던 닉네임보다 짧고
            // 접두사가 되더라도 완전히 같은 닉네임이 아니므로 Trie 알고리즘의 if (*key == '\0')에 의해 NULL 값이 리턴되어
            // 찾지 못했다고 나온다!

            // 찾지못한 닉네임은 insert를 해준다
            if (nick_cnt == -1)
            {
                root->insert(input.c_str());
            }
        }

        // 닉네임이 한번만 쓰였다면 그대로
        if (nick_cnt == 1)
        {
            cout << ans << "\n";
        }
        else // 닉네임이 한번 이상 쓰였다면 쓰일때 마다 닉네임 뒤에 +1 씩 숫자를 붙여 출력
        {
            cout << ans + to_string(nick_cnt) << "\n";
        }
    }

    return 0;
}