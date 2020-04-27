#include <iostream>
#include <vector>
#include <string>
using namespace std;

 int n;
 int sign[10][10];
 int ans[10];

 bool check(int index) // a�� �����Ͽ� s�� ���鶧 sign ���� ������ Ȯ��
 {
     int sum = 0;
     for (int i = index; i >= 0; i--)
     {
         sum += ans[i];
         if (sign[i][index] == 0)
         {
             if (sum != 0)
             {
                 return false;
             }
         }
         else if (sign[i][index] < 0)
         {
             if (sum >= 0)
             {
                 return false;
             }
         }
         else if (sign[i][index] > 0)
         {
             if (sum <= 0)
             {
                 return false;
             }
         }
     }
     return true;
 }

 bool go(int index) // ���� �ε����� ���Ͽ� �־��� �ε�ȣ�� ��ġ�ϴ��� bool�� ���� �˻縦 �����Ѵ�.
 {
     if (index == n)
     {
         return true;
     }
     if (sign[index][index] == 0) { // 0�� ���� ���⼭ ó���Ѵ�.
         ans[index] = 0;
         return check(index) && go(index + 1);
     }
     for (int i = 1; i <= 10; ++i)
     {
         ans[index] = sign[index][index] * i; // index index��ġ�� �ڱ��ڽ��̰� ��ȣ�� �� �� �����Ƿ� -10 ~ 10�� �ƴ� 1 ~ 10 ���� �Ѵ�.
         if (check(index) && go(index + 1))
         {
             return true;
         }
     }
     return false;
 }

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int idx = 0;
    string s;
    cin >> n;
    cin >> s;

    for (int i = 0; i < n; ++i)
    {
       for (int j = i; j < n; ++j)
       {
           if (s[idx] == '0')
           {
               sign[i][j] = 0;
           }
           else if (s[idx] == '+')
           {
               sign[i][j] = 1;
           }
           else
           {
               sign[i][j] = -1;
           }
           idx += 1;
       }
    }

    go(0);

    for (int i = 0; i < n; ++i)
    {
        cout << ans[i] << ' ';
    }
    cout << "\n";

    return 0;
}
