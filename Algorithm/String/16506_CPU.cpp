#include <bits/stdc++.h>

using namespace std;

string cmp[] = { "ADD","ADDC","SUB","SUBC","MOV","MOVC","AND","ANDC","OR","ORC","NOT","NOTC","MULT","MULTC","LSFTL","LSFTLC","LSFTR","LSFTRC","ASFTR","ASFTRC","RL","RLC","RR","RRC" };

string bin(int x, int digit)
{
	string t;
	while (x > 0)
	{
		if (x & 1) t += "1";
		else t += "0";
		x /= 2;
	}
	for (int i = t.size(); i < digit; i++)
		t += "0";
	reverse(t.begin(), t.end());
	return t;
}

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int tc;
	cin >> tc;
	while (tc--)
	{
		string s;
		int a, b, c;
		cin >> s >> a >> b >> c;
		int idx;
		for (int i = 0; i < 24; i++)
		{
			if (cmp[i] == s)
			{
				idx = i;
				break;
			}
		}
		string ans;
		ans += bin(idx / 2, 4);
		if (idx & 1) ans += "10";
		else ans += "00";
		ans += bin(a, 3);
		ans += bin(b, 3);
		if (idx & 1)
			ans += bin(c, 4);
		else
			ans += bin(c, 3) + "0";
		cout << ans << "\n";
	}

	return 0;
}