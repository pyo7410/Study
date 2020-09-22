#include <iostream>
#include <list>
#include <queue>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    list<char> input_order;
    string input;
    
    while (n--)
    {
        cin >> input;

        auto cursor = input_order.begin();
        for (int i = 0; i < input.length(); ++i)
        {
            if (input[i] == '<')
            {
                if (cursor != input_order.begin())
                {
                    cursor--;
                }
            }
            else if (input[i] == '>')
            {
                if (cursor != input_order.end())
                {
                    cursor++;
                }
            }
            else if (input[i] == '-')
            {
                if (cursor != input_order.begin())
                {
                    // 커서는 한칸 앞으로 가있다.
                    cursor--;
                    cursor = input_order.erase(cursor);
                }
            }
            else
            {
                // insert는 해당 cursor 위치에 삽입하고 뒤의 원소들을 뒤로 민다.
                cursor = input_order.insert(cursor, input[i]);
                cursor++;
            }
        }

        for (auto password : input_order)
        {
            cout << password;
        }
        cout << "\n";

        input_order.clear();
    }

    return 0;
}