#include <iostream>
#include <vector>
using namespace std;

void star(int n) {
	vector<char> v;
	for (int i = 0; i < n; i++) {
		v.push_back('*');
	}

	for (int i = 0; i < n; i++) {
		for (int j = v.size() - 1; j >= 0; j--)
		{
			cout << v[i];
		}
		
		v[i] = '1';
		cout << "\n";
	}
}



int main()
{
	int num;

	cin >> num;

	star(num);

	return 0;
}