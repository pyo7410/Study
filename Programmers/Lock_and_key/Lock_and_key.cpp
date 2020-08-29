#include <iostream>
#include <string>
#include <vector>
using namespace std;

void turning_key(vector<vector<int>> &key)
{
    int key_size = key.size();
    // 90도로 돌린 값을 저장할 배열
    vector<vector<int>> turn_key(key_size, vector<int>(key_size));

    for (int i = 0; i < key_size; ++i)
    {
        for (int j = 0; j < key_size; ++j)
        {
            // 90도 회전시 행은 열로 바뀌고 행은 역순으로 열이 된다.
            turn_key[j][(key_size - 1) - i] = key[i][j];
        }
    }

    key = turn_key;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock)
{
    bool answer = false;
    int lock_size = lock.size();
    int key_size = key.size();

    // key를 lock의 전체부분에 대해서 조사하기 위해서는 3배의 크기가 필요하다.
    vector<vector<int>> search_lock(lock_size * 3, vector<int>(lock_size * 3, 0));

    // 시계방향으로 돌리면 4번이 소모된다
    int search_lock_size = search_lock.size();
    for (int turn_cnt = 0; turn_cnt < 4; ++turn_cnt)
    {
        // 3배 크기의 배열 한 가운데의 lock을 위치시킨다.
        for (int i = 0; i < lock_size; ++i)
        {
            for (int j = 0; j < lock_size; ++j)
            {
                search_lock[lock_size + i][lock_size + j] = lock[i][j];
            }
        }

        // 3배로 확장한 lock을 복사하여 매번 검사하는 벡터
        vector<vector<int>> search_key;
        bool isRight = true;
        for (int i = 0; i < search_lock_size - key_size; ++i)
        {
            for (int j = 0; j < search_lock_size - key_size; ++j)
            {
                isRight = true;
                search_key.clear();
                search_key = search_lock;

                // 열쇠와 구멍을 찾아 값을 바꾸어 준다.
                for (int k = 0; k < key_size; ++k)
                {
                    for (int l = 0; l < key_size; ++l)
                    {
                        // 열쇠의 돌기와 자물쇠의 돌기는 만나서는 안된다!
                        if (key[k][l] == 1 && search_key[k + i][l + j] == 1)
                        {
                            isRight = false;
                            break;
                        }

                        if (key[k][l] == 1 && search_key[k + i][l + j] == 0)
                        {
                            search_key[k + i][l + j] = 1;
                        }
                    }
                    if (!isRight)
                    {
                        break;
                    }
                }

                if (!isRight)
                {
                    continue;
                }

                // 열쇠와 자물쇠 구멍이 맞았는지 검사!
                for (int k = 0; k < lock_size; ++k)
                {
                    for (int l = 0; l < lock_size; ++l)
                    {
                        if (search_key[lock_size + k][lock_size + l] == 0)
                        {
                            isRight = false;
                            break;
                        }
                    }
                    if (!isRight)
                    {
                        break;
                    }
                }

                if (isRight)
                {
                    return true;
                }
            }
        }

        turning_key(key);
    }

    return answer;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int key_i;
    int lock_i;

    cin >> key_i;
    cin >> lock_i;

    vector<vector<int>> key(key_i, vector<int>(key_i));
    vector<vector<int>> lock(lock_i, vector<int>(lock_i));

    for (int i = 0; i < key_i; ++i)
    {
        for (int j = 0; j < key_i; ++j)
        {
            cin >> key[i][j];
        }
    }

    for (int i = 0; i < lock_i; ++i)
    {
        for (int j = 0; j < lock_i; ++j)
        {
            cin >> lock[i][j];
        }
    }

    if (solution(key, lock))
    {
        cout << "true" << "\n";
    }
    else
    {
        cout << "false" << "\n";
    }
    

    return 0;
}
