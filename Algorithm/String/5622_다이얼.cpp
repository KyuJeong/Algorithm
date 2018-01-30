#include <iostream>
#include <string>

using namespace std;

string s;
int tme;

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> s;
	int num[26];
	int tmp = 0;

	for (int i = 3; i < 11; i++)
	{
		num[tmp++] = i;
		num[tmp++] = i;
		num[tmp++] = i;
		if (i == 8 || i == 10)
			num[tmp++] = i;
	}

	for (int i = 0; i < s.size(); i++)
	{
		char cur = s[i];
		tme += num[cur - 'A'];
	}

	cout << tme;

	return 0;
}