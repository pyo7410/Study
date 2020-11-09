#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Student {
public:
    int score;
    string name;

    Student(string name, int score)
    {
        this->name = name;
        this->score = score;
    }

    bool operator<(Student &other)
    {
        return this->score < other.score;
    }
};

vector<Student> v;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    string name;
    int score;

    for (int i = 0; i < n; ++i)
    {
        cin >> name >> score;
        v.push_back(Student(name, score));
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < n; ++i)
    {
        cout << v[i].name << ' ';
    }

    return 0;
}