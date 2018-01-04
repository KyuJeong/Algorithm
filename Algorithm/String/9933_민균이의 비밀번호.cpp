#include <iostream>
#include <string>
#include <algorithm>
#include <set>
using namespace std;

int N;
string temp;
set<string> word;
string answer;

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> N;

	set<string>::iterator iter;

	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		word.insert(temp);
		reverse(temp.begin(), temp.end());
		iter = word.find(temp);
		if (iter != word.end())
		{
			answer = temp[temp.size() / 2];
			break;
		}
		word.insert(temp);
	}

	cout << temp.size() << " " << answer;

	return 0;
}