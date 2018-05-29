#include <bits/stdc++.h>

using namespace std;

string BigSum(string s1, string s2)
{
	string ret = "";
	if (s1.size() < s2.size())
		swap(s1, s2);

	for (int i = s1.size() - s2.size(); i > 0; i--)
	{
		s2 += '0';
	}

	int carry = 0;

	for (int i = 0; i < s2.size(); i++)
	{
		int up = s1[i] - '0';
		int down = s2[i] - '0';
		int res = up + down;
		res += carry;
		carry = res / 10;
		res = res % 10;
		char c = res + '0';
		ret.push_back(c);
	}

	if (carry == 1)
		ret += '1';

	return ret;
}

string BigMul(string s1, string s2)
{
	string ret = "0";
	if (s1.size() < s2.size())
		swap(s1, s2);

	int cnt = 0;

	for (int i = s2.size() - 1; i >= 0; i--)
	{
		int up = s2[i] - '0';
		int carry = 0;
		string cur = "";

		for (int j = s1.size() - 1; j >= 0; j--)
		{
			int down = s1[j] - '0';
			int res = up * down;
			res += carry;
			carry = res / 10;
			res = res % 10;
			char c = res + '0';
			cur.push_back(c);
		}
		if (carry >= 1)
			cur.push_back(carry + '0');

		string cur_add_zero;
		for (int i = 0; i < cnt; i++)
			cur_add_zero.push_back('0');
		cur_add_zero += cur;
		ret = BigSum(ret, cur_add_zero);
		cnt++;
	}

	reverse(ret.begin(), ret.end());
	
	return ret;
}

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	string s1, s2;

	cin >> s1 >> s2;

	if (s1 == "0" || s2 == "0")
	{
		cout << "0";
		return 0;
	}

	string s = BigMul(s1, s2);

	cout << s;

	return 0;
}