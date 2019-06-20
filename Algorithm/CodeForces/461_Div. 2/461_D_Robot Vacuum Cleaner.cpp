#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 1e9;

typedef pair <double, string> pis;

int n;
vector <pis> v;
string tmp;

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		double ns = 0;
		double nh = 0;
		for (auto j : tmp)
		{
			if (j == 's')
				ns++;
			else
				nh++;
		}
		double rat;
		
		if (nh == 0)
		{
			rat = MAX;
		}
		else
		{
			rat = ns / nh;
		}

		v.push_back(pis(-rat, tmp));
	}

	sort(v.begin(), v.end());

	long long cs = 0;
	long long ch = 0;
	long long ans = 0;

	for (auto i : v)
	{
		string s = i.second;
		for (auto j : s)
		{
			if (j == 's')
				cs++;
			else
				ans += cs;
		}
	}

	cout << ans;

	return 0;
}