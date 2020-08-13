#include <iostream>
#include <string>
#include <cstring>
using namespace std;

// https://jason9319.tistory.com/129
// https://twpower.github.io/187-trie-concept-and-basic-problem

class Trie {
private:
    bool finish; // ������ ���� ǥ��
    bool nextChild; // ���� �ڽ��� �ִ���
    Trie* next[26]; // ���ĺ��� 26���� �̹Ƿ�

public:
    Trie() : finish(false) // finish�� false�� �ʱ�ȭ�ϰ� �����ڽ���
    {
        memset(next, 0, sizeof(next));
    }

    ~Trie() 
    {
        for (int i = 0; i < 26; ++i)
        {
            if (next[i]) // next[i]�� ���ĺ��� ����ִٸ�
            {
                delete next[i]; // next[i] �޸� ����
            }
        }
    }

    void insert(const char* key) // ���ڿ��� ���� �ּҰ� �Ű������� ���Եȴ�.
    {
        if (*key == '\0') // key�� null ���̶��
        {
            finish = true; // ���ڿ��� ������ �����̹Ƿ� ǥ��
        }
        else
        {
            int curr = *key - 'a'; // �ҹ��� ��ġ�� ��ȯ(��Ȳ�� �°� �빮�ڴ� 'A', ���ڴ� '0'����)
            
            if (next[curr] == NULL) // �ش� ���ĺ��� ����ִٸ�
            {
                next[curr] = new Trie(); // Ž���� ó���Ǵ� �����̹Ƿ� �����Ҵ�
            }

            nextChild = true;

            next[curr]->insert(key + 1); // key + 1�� �Ͽ� ���� ���ڸ� ����
        }    
    }

    Trie* find(const char* key) // ���ڿ��� ���� �ּҰ� �Ű������� ���Եȴ�.
    {
        if (*key == '\0') // ���ڿ��� ������ ��ġ���
        {
            if (finish) // ������ �κ��̶��
            {
                return this; // ������ ��ġ�� ��ȯ
            }

            return NULL; 
        }
        
        int curr = *key - 'a'; // �ҹ��� ��ġ�� ��ȯ(��Ȳ�� �°� �빮�ڴ� 'A', ���ڴ� '0'����)
        
        if (next[curr] == NULL) // ���� �ش� ���ĺ��� ����ִٸ�
        {
            return NULL; // ã�� ���� �����Ƿ� NULL ��ȯ
        }

        return next[curr]->find(key + 1); // key + 1�� �Ͽ� ���� ���ڵ� ����ִ��� �˻�
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

        // ���� input_str�� ���Ե� ���ڿ��� �ִٸ�
        if (root->find(input_str.c_str()))
        {
            ans += 1;
        }
    }

    cout << ans << "\n";
    
    return 0;
}
