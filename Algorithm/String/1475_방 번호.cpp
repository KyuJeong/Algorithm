#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string s;
char c[10];

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> s;

	for (int i = 0; i < s.size(); i++)
	{
		c[s[i] - '0']++;
	}

	c[6] += c[9];
	c[6] = (c[6] + 1) / 2;
	c[9] = 0;

	int ans = *max_element(c, c + 10);

	cout << ans;

	return 0;
}