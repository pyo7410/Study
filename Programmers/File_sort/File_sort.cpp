#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Info
{
public:
    string file_name;
    string file_head;
    int file_number;

    Info(string n, string h, int num)
    {
        this->file_name = n;
        this->file_head = h;
        this->file_number = num;
    }
};

bool cmp(Info a, Info b)
{
    // 사전순으로 순서가 같다면
    if (a.file_head == b.file_head)
    {
        // number 부분의 숫자가 작은 게 앞으로
        return a.file_number < b.file_number;
    }

    // 사전순으로 정렬
    return a.file_head < b.file_head;
}

vector<string> solution(vector<string> files) 
{
    vector<string> answer;
    vector<Info> vec;

    int file_num = files.size();

    for (int i = 0; i < file_num; ++i)
    {
        bool isHead = false;
        int cnt = 1;
        string fHead = "", fNumber = "";

        for (int j = 0; j < files[i].length(); ++j)
        {
            // Head 부분을 못 찾았다면
            if (!isHead)
            {
                // 해당 문자가 숫자인지
                if (isdigit(files[i][j]))
                {
                    // 숫자라면 Head가 끝나고 Number가 시작되는 부분이므로
                    // fNumber에 저장
                    fNumber += files[i][j];

                    // Head를 찾았으므로 true
                    isHead = true;
                }
                else
                {
                    // 숫자가 아니므로 fHead에 추가
                    fHead += files[i][j];
                }
            }
            else // Head 부분을 찾았다면 isHead = true 이므로
            {
                // 만약 Number 부분의 글자수가 5글자 이상이거나
                // 숫자가 아닌수가 나왔다면
                if (cnt >= 5 || !isdigit(files[i][j]))
                {
                   // 우선 Head를 대문자로 변환시켜준다.
                    transform(fHead.begin(), fHead.end(), fHead.begin(), ::toupper);
                    vec.push_back(Info(files[i], fHead, stoi(fNumber)));

                    // for문을 빠져나갔을때 vec에 값을 저장했는지 여부를 파악하기위해
                    // fHead와 fNumber의 값을 없에준다.
                    fHead = "";
                    fNumber = "";

                    // tail은 사실상 쓸 이유가 없으므로
                    // break
                    break;
                }
                else
                {
                    // 5글자 이하이고 숫자일경우
                    // Number 부분이므로 추가
                    fNumber += files[i][j];

                    // 글자수 +1 증가
                    cnt++;
                }
            }
        }

        // 만약 F12 같은 문자열이라면 vec에 값을 저장하지않고
        // 바로 for문을 빠져나오게 되므로 조건을 확인해서
        // 값을 저장하지 않았다면 값을 vec에 저장하게 해주어야 한다.
        if (fHead != "" && fNumber != "")
        {
            transform(fHead.begin(), fHead.end(), fHead.begin(), ::toupper);
            vec.push_back(Info(files[i], fHead, stoi(fNumber)));
        }
    }

    // stable_sort는 만약 a, a, a, a 라고 할 경우
    // 같은 값은 정렬이 끝난뒤에도 정렬전과 인덱스순서가 그대로 유지됨을 보장해준다.
    stable_sort(vec.begin(), vec.end(), cmp);

    for (auto v : vec)
    {
        answer.push_back(v.file_name);
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

    cin.ignore();
    vector<string> files(n);
    for (int i = 0; i < n; ++i)
    {
        getline(cin, files[i]);
    }

    solution(files);

    return 0;
}