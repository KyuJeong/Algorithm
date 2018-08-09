
#include <bits/stdc++.h>

using namespace std;

string bigSum(string a, string b)
{
	string s;
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
	
	return s;
}

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	string s1 = "1";
	string s2 = "1";
	int n;
	cin >> n;

	for (int i = 3; i <= n; i++)
	{
		string tmp = s2;
		s2 = bigSum(s1, s2);
		s1 = tmp;
	}

	cout << s2;

	return 0;
}