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
        list<int>::iterator iter;
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
            cin >> command >> x >> y;

            if (command = 'I')
            {
                list<int> insert_cryptogram;
                iter = cryptogram.begin();

                for (int j = 0; j < x; ++j)
                {
                    ++iter;
                }

                for (int j = 0; j < y; ++j)
                {
                    cin >> crypt;
                    insert_cryptogram.push_back(crypt);
                }

                cryptogram.insert(iter, insert_cryptogram.begin(), insert_cryptogram.end());
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
