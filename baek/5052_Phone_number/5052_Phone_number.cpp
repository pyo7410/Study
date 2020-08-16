#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

class Trie {
private:
    bool finish; // 끝나는 지점 표시
    Trie* next[26]; // 알파벳이 26 가지 이므로

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
        // key가 null이라면
        if (*key == '\0')
        {
            finish = true; // 문자열이 끝나는 지점임을 표시
        }
        else
        {
            int curr = *key - '0'; // 숫자 위치로 변환 (상황에 맞게 대문자는 'A', 소문자는 'a'로 대체)

            if (next[curr] == NULL) // 해당 위치가 비어있다면
            {
                next[curr] = new Trie(); // 동적할당
            }

            next[curr]->insert(key + 1); // key + 1을 하여 다음 문자를 삽입
        }
    }

    Trie* find(const char* key)
    {
        if (*key == '\0') // key가 null이라면 즉, 문자열에서 마지막 문자라면
        {
            return this; // 0이 아닌 값을 리턴
        }

        int curr = *key - '0'; // 숫자 위치로 변환 (상황에 맞게 대문자는 'A', 소문자는 'a'로 대체)

        if (next[curr] == NULL) // 해당 위치가 비어있다면
        {
            return NULL; // 찾는 값이 없으므로 NULL 반환
        }

        return next[curr]->find(key + 1); // key + 1을 하여 다음 문자도 있는지 검색
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
