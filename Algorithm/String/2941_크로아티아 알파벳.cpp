#include <iostream>
#include <string>
using namespace std;

int cnt;
string tmp, s;

int main()
{
	std::ios::sync_with_stdio(false);

	s = "00";
	cin >> tmp;
	s += tmp;

	for (int i = s.size() - 1; i >= 2; i--)
	{
		if (s[i] == '-')
			i--;
		else if (s[i] == '=')
		{
			if (s[i - 1] == 'z' && s[i - 2] == 'd')
				i -= 2;
			else
				i--;
		}
		else if (s[i] == 'j')
		{
			if (s[i - 1] == 'l' || s[i - 1] == 'n')
				i--;
		}
		cnt++;
	}
	cout << cnt;

	return 0;
}