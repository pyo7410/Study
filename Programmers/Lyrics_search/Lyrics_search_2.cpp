#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

class Trie 
{
private:
    bool finish;    // 끝나는 지점 표시
    int child_cnt;
    Trie *next[26];     // 알파벳은 26가지 이므로

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
        // 문자에서 중복된 알파벳이 더라도 frode, frost 는 다르지만
        // insert 할때 마다 +1을 하게 하여 f, r, o 까지의 cnt는 2가 된다!
        // 즉 물음표가 나타나면 물음표일때의 child_cnt가 물음표에 모든 단어가 된다.
        child_cnt += 1;

         // key가 null 이라면
        if (*key == '\0')
        {
            // 문자열이 끝나는 지점임으로 표시
            finish = true;
        }
        else
        {
            int curr = *key - 'a'; // 알파벳 소문자의 위치로 변환

            // 해당 위치가 비었다면
            if (next[curr] == NULL)
            {
                // 해당 알파벳 위치에 동적할당
                next[curr] = new Trie();
            }

            next[curr]->insert(key + 1);
        }
    }

    // 물음표 일경우 자식의 갯수만 리턴하면 된다.
    // 물음표는 무조건 한개 이상이 들어가 있으므로
    // 무조건 마지막은 물음표가 되게 된다.
    int find(const char* key)
    {
        // 만약 현재 문자가 물음표 라면
        if (*key == '?')
        {
            return child_cnt;
        }

        int curr = *key - 'a';

        if (next[curr] == NULL) // 현재 문자 위치가 비어있다면
        {
            return 0;
        }

         return next[curr]->find(key + 1);
    }
};

// 1 ~ 10000 까지 길이의 문자열을 넣기 위한 Trie 배열
// 포인트형 배열이므로 * 붙이는걸 잊지마라
// 함수 내부의 스택 크기 제한이 있기에
// 전역 변수로 해야 스택의 크기가 늘어난다!
Trie *root[10001];
Trie *reverse_root[10001];

// ?가 접두사일 경우 뒤에 붙은 알파벳으로 검색하면 더욱 빠르다.
// 즉, 뒤집은 문자열을 저장할 Trie를 하나 만들면 된다!
vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;

    // words의 값들을 Trie에 넣는다.
    for (int i = 0; i < words.size(); ++i)
    {
        string word = words[i];
        int word_len = word.length();

        // 해당 문자열 길이만큼이 단 한번도 들어오지 않았다면
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

        // // 해당 문자열 길이만큼이 단 한번도 들어오지 않았다면
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

        // 만약 물음표가 접두사라면
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
