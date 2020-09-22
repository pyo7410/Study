#include <iostream>
#include <vector>
#include <stack>
using namespace std;

typedef long long ll;

stack<int> s;

int main(){
	ios_base::sync_with_stdio(false); 
    cout.tie(nullptr);
    cin.tie(nullptr);

	int n; 
    cin >> n;

	vector<int> v(n);
	for(int i = 0; i < n; i++) 
    {
        cin >> v[i];
    }

	ll ans = 0;
	for(int i = 0; i < n; i++)
    {
        // 해당 높이에서 볼 수 있는 옥상들의 볼 수 있는 높이까지 저장된다.
		while(!s.empty() && s.top() <= v[i])
        {
            s.pop();
        } 
		ans += (ll)s.size();

		s.push(v[i]);
	}

	cout << ans << "\n";

    return 0;
}