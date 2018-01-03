#include <iostream>
#include <string>
#include <set>
using namespace std;

int N;
set <string> person;
string name;
string action;

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> name >> action;
		if (action == "enter")
			person.insert(name);
		else
			person.erase(name);
	}

	set <string> ::reverse_iterator iter;
	for (iter = person.rbegin(); iter != person.rend(); iter++)
	{
		cout << *iter << "\n";
	}

	return 0;
}