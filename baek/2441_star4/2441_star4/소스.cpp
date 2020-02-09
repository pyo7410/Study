#include <iostream>
#include <vector>
using namespace std;

void star(int n) {
	vector<char> v;
	for (int i = 0; i < n; i++) {
		v.push_back('*');
	}

	for (int i = 0; i < n; i++) {
		
		for (int j = 0; j < n; j++)
		{
			cout << v[j];
		}

		v[i] = ' ';
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