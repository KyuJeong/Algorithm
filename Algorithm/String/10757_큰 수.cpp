#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string a, b;
string s;

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> a >> b;

	if (a.size() < b.size())
		swap(a, b);

	int j = b.size() - 1;
	char tmp;

	for (int i = a.size() - 1; i >= 0; i--)
	{
		if (j >= 0)
			tmp = a[i] + b[j] - '0';
		else
			tmp = a[i];

		s += tmp;

		j--;
	}

	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] > '9')
		{
			s[i] -= 10;
			if (i == s.size() - 1)
				s += '1';
			else
				s[i + 1] += 1;
		}
	}

	reverse(s.begin(), s.end());

	cout << s;

	return 0;
}