#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;


// uid와 bid의 내용이 전부 맞는지 확인
// *는 모든 문자열에 매칭
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

// banned_id와 매칭여부를 판단
bool check[9];
// user_id 배열의 개수를 저장
int user_size;
// banned_id의 개수를 저장
int banned_size;
// 중복을 제거한 banned_id와 매칭된 user_id의 0부터 정렬된 index값을 저장
// 정렬된 index를 가지고 있으므로 중복을 제거 가능
// ex) user_id   = "frodo", "fradi", "crodo", "abc123", "frodoc" 일 경우
//     banned_id = "*rodo", "******", "******" 라면
//     frodo abc123 frodoc || frodo frodoc abc123이 나온다면
//     해당 index들은 034와 043 이고 이를 오름차순 정렬하면 034, 034가 되므로 중복을 제거할 수 있다.
set<string> foundID;

// index : banned_id의 인덱스
// position : banned_id와 매칭된 user_id의 인덱스
void findID(int index, string position, vector<string> user_id, vector<string> banned_id)
{
    // index가 banned_id 배열의 끝이라면
    if (index == banned_size)
    {
        // set에 넣어 중복을 없에기 위해 banned_id와 매칭된 user_id의 인덱스를 sort
        // ex) frodo, crodo, abc123 | crodo, frodo, abc123
        sort(position.begin(), position.end());
        // set에 삽입, 만약 중복이라면 중복은 제거됨.
        foundID.insert(position);
        return;
    }

    // ban당한 id
    string bid = banned_id[index];

    for (int i = 0; i < user_size; ++i)
    {
        // user id
        string uid = user_id[i];

        // 만약 bid와 uid의 길이가 다르면 비교할 필요가 없다.
        if (uid.length() != bid.length())
        {
            continue;
        }

        // 이미 banned_id에 매칭된 user_id일 경우 이미 포함됬으므로 제외해야한다.
        if (check[i])
        {
            continue;
        }

        // uid와 bid가 같다면
        if (isEqual(uid, bid))
        {
            // 해당 uid가 bid에 매칭됬음을 표기
            check[i] = true;

            // 현재 index의 banned_id와 매칭된 uid를 찾았으므로
            // 다음 index의 banned_id와 매칭될 uid를 찾게한다.
            // position 문자열에 현재 uid의 인덱스를 담아 어떤 uid와 매칭됬는지 표시한다.
            findID(index + 1, position + to_string(i), user_id, banned_id);

            // 모든 경우를 봐야하기 때문에
            // 해당 uid의 매칭이 됬음을 다시 매칭이 안됬음으로 바꾸고
            // 다음 user_id와 banned_id를 비교해본다.
            // "frodo", "fradi", "crodo", "abc123", "frodoc" 일 경우
            // ex) frodo, crodo, abc123 와 fradi, crodo, abc123은 다르다.
            //     즉, frodo 다음에 있는 fradi에 대해서도 다음 인덱스의 모든 banned_id와
            //     매칭이 되는지 비교해야 한다.
            check[i] = false;
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;

    user_size = user_id.size();
    banned_size = banned_id.size();
    
    // banned_id의 첫 인덱스인 0
    // banned_id와 매칭된 user_id의 인덱스를 기록할 ""
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