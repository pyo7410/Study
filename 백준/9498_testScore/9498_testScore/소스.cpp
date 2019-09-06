#include <iostream>
using namespace std;

int main()
{
	int score;
	cin >> score;

	if (score >= 90)
		cout << "A" << endl;
	else if (score < 90 && score >= 80)
		cout << "B" << endl;
	else if (score < 80 && score >= 70)
		cout << "C" << endl;
	else if (score < 70 && score >= 60)
		cout << "D" << endl;
	else if (score < 60)
		cout << "F" << endl;
}