#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

bool comp(string s1, string s2)
{
    return s1.length() < s2.length();
}

class Trie {
private:
    bool finish;
    int child_cnt;
    Trie *next[26];
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
            int curr = *key - '0';
            if (next[curr] == NULL)
            {
                next[curr] = new Trie();
            }
            next[curr]->insert(key + 1);
        }
    }

    bool find(const char *key)
    {
        int curr = *key - '0';

        if (*key =='\0')
        {
            if (child_cnt > 1)
            {
                return false;
            }
            else
            {
                return true;
            }
        }

        return next[curr]->find(key + 1);
    }
};

bool solution(vector<string> phone_book) 
{
    bool answer = true;
    int phone_book_size = phone_book.size();
    Trie *root = new Trie();

    for (int i = 0; i < phone_book_size; ++i)
    {
        root->insert(phone_book[i].c_str());
    }

    sort(phone_book.begin(), phone_book.end(), comp);

    for (int i = 0; i < phone_book_size; ++i)
    {
        if (root->find(phone_book[i].c_str()))
        {
            continue;
        }
        else
        {
            answer = false;
            break;   
        }
    }

    return answer;
}

/*
// 문자열을 이용한 풀이
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    // string은 숫자 크기가아니고 사전순으로 정렬됨을 주의
    sort(phone_book.begin(), phone_book.end());

    for (int i = 0; i < phone_book.size() - 1; ++i)
    {
        if (phone_book[i] == phone_book[i + 1].substr(0, phone_book[i].length()))
        {
            return false;
        }
    }

    return answer;
}
*/

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    vector<string> phone_book(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> phone_book[i];
    }

    cout << solution(phone_book);

}