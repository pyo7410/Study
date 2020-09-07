#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;


// uid�� bid�� ������ ���� �´��� Ȯ��
// *�� ��� ���ڿ��� ��Ī
bool isEqual(string uid, string bid)
{
    int len = uid.length();

    for (int i = 0; i < len; ++i)
    {
        if (bid[i] == '*')
        {
            continue;
        }
        if (uid[i] != bid[i])
        {
            return false;
        }
    }
    return true;
}

// banned_id�� ��Ī���θ� �Ǵ�
bool check[9];
// user_id �迭�� ������ ����
int user_size;
// banned_id�� ������ ����
int banned_size;
// �ߺ��� ������ banned_id�� ��Ī�� user_id�� 0���� ���ĵ� index���� ����
// ���ĵ� index�� ������ �����Ƿ� �ߺ��� ���� ����
// ex) user_id   = "frodo", "fradi", "crodo", "abc123", "frodoc" �� ���
//     banned_id = "*rodo", "******", "******" ���
//     frodo abc123 frodoc || frodo frodoc abc123�� ���´ٸ�
//     �ش� index���� 034�� 043 �̰� �̸� �������� �����ϸ� 034, 034�� �ǹǷ� �ߺ��� ������ �� �ִ�.
set<string> foundID;

// index : banned_id�� �ε���
// position : banned_id�� ��Ī�� user_id�� �ε���
void findID(int index, string position, vector<string> user_id, vector<string> banned_id)
{
    // index�� banned_id �迭�� ���̶��
    if (index == banned_size)
    {
        // set�� �־� �ߺ��� ������ ���� banned_id�� ��Ī�� user_id�� �ε����� sort
        // ex) frodo, crodo, abc123 | crodo, frodo, abc123
        sort(position.begin(), position.end());
        // set�� ����, ���� �ߺ��̶�� �ߺ��� ���ŵ�.
        foundID.insert(position);
        return;
    }

    // ban���� id
    string bid = banned_id[index];

    for (int i = 0; i < user_size; ++i)
    {
        // user id
        string uid = user_id[i];

        // ���� bid�� uid�� ���̰� �ٸ��� ���� �ʿ䰡 ����.
        if (uid.length() != bid.length())
        {
            continue;
        }

        // �̹� banned_id�� ��Ī�� user_id�� ��� �̹� ���ԉ����Ƿ� �����ؾ��Ѵ�.
        if (check[i])
        {
            continue;
        }

        // uid�� bid�� ���ٸ�
        if (isEqual(uid, bid))
        {
            // �ش� uid�� bid�� ��Ī������ ǥ��
            check[i] = true;

            // ���� index�� banned_id�� ��Ī�� uid�� ã�����Ƿ�
            // ���� index�� banned_id�� ��Ī�� uid�� ã���Ѵ�.
            // position ���ڿ��� ���� uid�� �ε����� ��� � uid�� ��Ī����� ǥ���Ѵ�.
            findID(index + 1, position + to_string(i), user_id, banned_id);

            // ��� ��츦 �����ϱ� ������
            // �ش� uid�� ��Ī�� ������ �ٽ� ��Ī�� �ȉ������� �ٲٰ�
            // ���� user_id�� banned_id�� ���غ���.
            // "frodo", "fradi", "crodo", "abc123", "frodoc" �� ���
            // ex) frodo, crodo, abc123 �� fradi, crodo, abc123�� �ٸ���.
            //     ��, frodo ������ �ִ� fradi�� ���ؼ��� ���� �ε����� ��� banned_id��
            //     ��Ī�� �Ǵ��� ���ؾ� �Ѵ�.
            check[i] = false;
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;

    user_size = user_id.size();
    banned_size = banned_id.size();
    
    // banned_id�� ù �ε����� 0
    // banned_id�� ��Ī�� user_id�� �ε����� ����� ""
    findID(0, "", user_id, banned_id);

    answer = foundID.size();

    return answer;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<string> user_id(n);
    vector<string> banned_id(m);
    for (int i = 0; i < n; ++i)
    {
        cin >> user_id[i];
    }

    for (int i = 0; i < m; ++i)
    {
        cin >> banned_id[i];
    }

    cout << solution(user_id, banned_id) << endl;
}