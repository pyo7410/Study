#include <iostream>
#include <vector>
#include <string>
using namespace std;

 int n;
 int sign[10][10];
 int ans[10];

 bool check(int index) // a를 조합하여 s를 만들때 sign 값과 같은지 확인
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

 bool go(int index) // 다음 인덱스와 비교하여 주어진 부등호와 일치하는지 bool을 통해 검사를 시행한다.
 {
     if (index == n)
     {
         return true;
     }
     if (sign[index][index] == 0) { // 0인 경우는 여기서 처리한다.
         ans[index] = 0;
         return check(index) && go(index + 1);
     }
     for (int i = 1; i <= 10; ++i)
     {
         ans[index] = sign[index][index] * i; // index index위치는 자기자신이고 부호를 알 수 있으므로 -10 ~ 10이 아닌 1 ~ 10 까지 한다.
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
