#include <iostream>
#include <string>
#include <vector>
using namespace std;

void turning_key(vector<vector<int>> &key)
{
    int key_size = key.size();
    // 90���� ���� ���� ������ �迭
    vector<vector<int>> turn_key(key_size, vector<int>(key_size));

    for (int i = 0; i < key_size; ++i)
    {
        for (int j = 0; j < key_size; ++j)
        {
            // 90�� ȸ���� ���� ���� �ٲ�� ���� �������� ���� �ȴ�.
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

    // key�� lock�� ��ü�κп� ���ؼ� �����ϱ� ���ؼ��� 3���� ũ�Ⱑ �ʿ��ϴ�.
    vector<vector<int>> search_lock(lock_size * 3, vector<int>(lock_size * 3, 0));

    // �ð�������� ������ 4���� �Ҹ�ȴ�
    int search_lock_size = search_lock.size();
    for (int turn_cnt = 0; turn_cnt < 4; ++turn_cnt)
    {
        // 3�� ũ���� �迭 �� ����� lock�� ��ġ��Ų��.
        for (int i = 0; i < lock_size; ++i)
        {
            for (int j = 0; j < lock_size; ++j)
            {
                search_lock[lock_size + i][lock_size + j] = lock[i][j];
            }
        }

        // 3��� Ȯ���� lock�� �����Ͽ� �Ź� �˻��ϴ� ����
        vector<vector<int>> search_key;
        bool isRight = true;
        for (int i = 0; i < search_lock_size - key_size; ++i)
        {
            for (int j = 0; j < search_lock_size - key_size; ++j)
            {
                isRight = true;
                search_key.clear();
                search_key = search_lock;

                // ����� ������ ã�� ���� �ٲپ� �ش�.
                for (int k = 0; k < key_size; ++k)
                {
                    for (int l = 0; l < key_size; ++l)
                    {
                        // ������ ����� �ڹ����� ����� �������� �ȵȴ�!
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

                // ����� �ڹ��� ������ �¾Ҵ��� �˻�!
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
