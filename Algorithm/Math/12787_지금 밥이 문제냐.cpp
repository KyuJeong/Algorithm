#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector <ll> vll;
typedef vector <string> vs;

int T;

vs Divide(string s)
{
	vs num(8);
	int pre = 0;
	int idx = 0;
	for (int i = 0; i < s.size(); i++)
	{
		string s2;
		if (s[i] != '.')
			continue;
		int len = i - pre;
		s2 = s.substr(pre, len);
		pre = i + 1;
		num[idx] = s2;
		idx++;
	}
	int len = s.size() - pre;
	string s2 = s.substr(pre, len);
	num[7] = s2;
	reverse(num.begin(), num.end());

	return num;
}

string BigSumReverse(string s1, string s2)
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
	if (s1 == "0" || s2 == "0")
		return "0";
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
		ret = BigSumReverse(ret, cur_add_zero);
		cnt++;
	}

	reverse(ret.begin(), ret.end());

	return ret;
}

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> T;

	while (T--)
	{
		int M;
		cin >> M;
		if (M == 1)
		{
			string s;
			cin >> s;
			string arr[8];
			vs num = Divide(s);
			string ans = "0";
			for (ll i = 0; i < 8; i++)
			{
				ll exp = (1LL << (8 * i));
				string mul = to_string(exp);
				string tmp = BigMul(num[i], mul);
				reverse(ans.begin(), ans.end());
				reverse(tmp.begin(), tmp.end());
				ans = BigSumReverse(ans, tmp);
				reverse(ans.begin(), ans.end());
			}
			cout << ans << "\n";
		}
		else
		{
			ull n;
			cin >> n;
			for (int i = 7; i >= 1; i--)
			{
				ull tmp = pow(2LL, 8 * i);
				ull cur = n / tmp;
				n %= tmp;
				cout << cur << ".";
			}
			cout << n << "\n";
		}
	}

	return 0;
}
