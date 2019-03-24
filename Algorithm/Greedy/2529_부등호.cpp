#include <bits/stdc++.h>

using namespace std;

int n;
int open, close;
string s;
vector <int> vc;

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> n;
	char c;
	for (int i = 0; i < n; i++)
	{
		cin >> c;
		s.push_back(c);
	}

	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		if (s[i] == '<') cnt++;
		else
		{
			vc.push_back(cnt);
			cnt = 0;
		}
	}
	vc.push_back(cnt);

	int maxx = 10;
	int len = vc.size();
	for (int i = 0; i < len; i++)
	{
		maxx--;
		if (vc[i] == 0)
		{
			cout << maxx;
			continue;
		}
		for (int j = vc[i]; j >= 0; j--)
			cout << maxx - j;
		maxx -= vc[i];
	}

	cout << "\n";

	vc.clear();
	cnt = 0;
	for (int i = 0; i < n; i++)
	{
		if (s[i] == '>') cnt++;
		else
		{
			vc.push_back(cnt);
			cnt = 0;
		}
	}
	vc.push_back(cnt);

	int minn = -1;
	len = vc.size();
	for (int i = 0; i < len; i++)
	{
		minn++;
		if (vc[i] == 0)
		{
			cout << minn;
			continue;
		}
		for (int j = vc[i]; j >= 0; j--)
			cout << minn + j;
		minn += vc[i];
	}

	return 0;
}