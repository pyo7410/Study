#include <iostream>
#include <list>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    for (int test_case = 1; test_case <= 10; ++test_case)
    {
        int len;
        cin >> len;

        list<int> cryptogram;
        list<int>::iterator begin_iter, end_iter;
        int crypt;
        for (int i = 0; i < len; ++i)
        {
            cin >> crypt;
            cryptogram.push_back(crypt);
        }

        int num;
        cin >> num;

        char command;
        int x, y;
        for (int i = 0; i < num; ++i)
        {
            cin >> command;
            
            if (command == 'I')
            {
                list<int> insert_cryptogram;

                cin >> x >> y;

                begin_iter = cryptogram.begin();
                for (int j = 0; j < x; ++j)
                {
                    ++begin_iter;
                }

                for (int j = 0; j < y; ++j)
                {
                    cin >> crypt;
                    insert_cryptogram.push_back(crypt);
                }

                cryptogram.insert(begin_iter, insert_cryptogram.begin(), insert_cryptogram.end());
            }
            else if (command == 'D')
            {
                cin >> x >> y;

                begin_iter = cryptogram.begin();
                for (int j = 0; j < x; ++j)
                {
                    ++begin_iter;
                }
                // end_iter은 begin_iter보다 뒤에 와야함을 잊지말것
                end_iter = begin_iter;

                for (int j = 0; j < y; ++j)
                {
                    ++end_iter;
                }

                cryptogram.erase(begin_iter, end_iter);
            }
            else if (command == 'A')
            {
                list<int> append_cryptogram;

                cin >> y;

                for (int j = 0; j < y; ++j)
                {
                    cin >> crypt;
                    append_cryptogram.push_back(crypt);
                }

                cryptogram.splice(cryptogram.end(), append_cryptogram);
            }
        }

        cout << "#" << test_case << " ";
        for (int i = 0; i < 9; ++i)
        {
            cout << cryptogram.front() << " ";
            cryptogram.pop_front();
        }
        cout << cryptogram.front() << "\n";
    }
    
    return 0;
}
