#include <iostream>
#include <string>
#include <cmath>

using namespace std;

string s;

int Convert()
{
	int ret = 0;

	int mul = 1;

	for (int i = s.size() - 1; i >= 0; i--)
	{
		int add;

		if (s[i] <= '9')
			add = s[i] - '0';
		else
			add = s[i] - 'A' + 10;

		ret += add * mul;
		mul *= 16;
	}

	return ret;
}

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> s;

	int ans = Convert();
	
	cout << ans;

	return 0;
}