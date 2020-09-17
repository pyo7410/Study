#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

class Trie {
private:
    Trie *next[26];
    bool finish;
    int child_cnt;
public:
    Trie() : finish(false), child_cnt(0)
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
        child_cnt++;
        if (*key == '\0')
        {
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

    int find(const char* key)
    {
        int len = 1;

        if (child_cnt == 1)
        {
            return 0;
        }

        if (*key == '\0')
        {
            return 0;
        }

        int curr = *key - 'a';
        
        return len + next[curr]->find(key + 1);
    }
};

int solution(vector<string> words) {
    int answer = 0;
    int wordCnt = words.size();

    Trie *root = new Trie();

    for (int i = 0; i < wordCnt; ++i)
    {
        root->insert(words[i].c_str());
    }

    for (int i = 0; i < wordCnt; ++i)
    {
        int temp = root->find(words[i].c_str());
        answer += temp;
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

    vector<string> words(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> words[i];
    }

    cout << solution(words) << endl;
}