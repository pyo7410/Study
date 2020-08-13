#include <iostream>
#include <string>
#include <cstring>
using namespace std;

// https://jason9319.tistory.com/129
// https://twpower.github.io/187-trie-concept-and-basic-problem

class Trie {
private:
    bool finish; // 끝나는 지점 표시
    bool nextChild; // 다음 자식이 있는지
    Trie* next[26]; // 알파벳이 26가지 이므로

public:
    Trie() : finish(false) // finish를 false로 초기화하고 생성자실행
    {
        memset(next, 0, sizeof(next));
    }

    ~Trie() 
    {
        for (int i = 0; i < 26; ++i)
        {
            if (next[i]) // next[i]에 알파벳이 들어있다면
            {
                delete next[i]; // next[i] 메모리 해제
            }
        }
    }

    void insert(const char* key) // 문자열의 시작 주소가 매개변수로 오게된다.
    {
        if (*key == '\0') // key가 null 값이라면
        {
            finish = true; // 문자열이 끝나는 지점이므로 표시
        }
        else
        {
            int curr = *key - 'a'; // 소문자 위치로 변환(상황에 맞게 대문자는 'A', 숫자는 '0'으로)
            
            if (next[curr] == NULL) // 해당 알파벳이 비어있다면
            {
                next[curr] = new Trie(); // 탐색이 처음되는 지점이므로 동적할당
            }

            nextChild = true;

            next[curr]->insert(key + 1); // key + 1을 하여 다음 문자를 삽입
        }    
    }

    Trie* find(const char* key) // 문자열의 시작 주소가 매개변수로 오게된다.
    {
        if (*key == '\0') // 문자열이 끝나는 위치라면
        {
            if (finish) // 마지막 부분이라면
            {
                return this; // 끝나는 위치를 반환
            }

            return NULL; 
        }
        
        int curr = *key - 'a'; // 소문자 위치로 변환(상황에 맞게 대문자는 'A', 숫자는 '0'으로)
        
        if (next[curr] == NULL) // 만약 해당 알파벳이 비어있다면
        {
            return NULL; // 찾는 값이 없으므로 NULL 반환
        }

        return next[curr]->find(key + 1); // key + 1을 하여 다음 문자도 들어있는지 검색
    }
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    Trie *root = new Trie();

    string input_str;
    for (int i = 0; i < n; ++i)
    {
        cin >> input_str;
        root->insert(input_str.c_str());
    }

    int ans = 0;
    for (int i = 0; i < m; ++i)
    {
        cin >> input_str;

        // 만약 input_str이 포함된 문자열이 있다면
        if (root->find(input_str.c_str()))
        {
            ans += 1;
        }
    }

    cout << ans << "\n";
    
    return 0;
}
