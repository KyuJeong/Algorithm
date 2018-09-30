#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define M_PI 3.14159265358979323846
#define fst first
#define snd second

int n;
vector <pair <ll, ll>> tmp;
vector <double> v;

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> n;
	tmp.resize(n);
	ll a, b;

	ll _max = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp[i].fst >> tmp[i].snd;
		_max = max(_max, tmp[i].fst * tmp[i].fst + tmp[i].snd * tmp[i].snd);
	}

	for (int i = 0; i < n; i++)
	{
		if (_max != tmp[i].fst * tmp[i].fst + tmp[i].snd * tmp[i].snd)
			continue;
		double x = tmp[i].fst;
		double y = tmp[i].snd;
		double deg = atan2(x, y) * 180 * (-1) / M_PI + 90;

		if ((x > 0 && y <= 0) || (x >= 0 && y < 0))
			v.push_back(360 + deg);
		else
			v.push_back(deg);
	}

	sort(v.begin(), v.end());

	double ans = 0;
	for (int i = 1; i < v.size(); i++)
		ans = max(ans, v[i] - v[i - 1]);

	ans = max(ans, v[0] + 360 - v[v.size() - 1]);

	cout.precision(10);
	cout << ans;

	return 0;
}