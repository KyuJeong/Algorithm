#include <bits/stdc++.h>

using namespace std;

#define INF 1e13

typedef long long ll;
typedef long double ld;
typedef pair <ld, ld> pld;

int N, M, L;
vector <pld> v;

ld Solve()
{
	ld ret = INF;
	ld half = N / 2;
	int len = v.size();
	for (int i = 1; i < len; i++)
	{
		if (v[i].second - v[i - 1].second > 0)
		{
			if (v[i].first - v[i].second > 0)
				continue;
			if (v[i].first + v[i].second < N)
				continue;
			ld dif = (v[i].second - v[i].first) / 2;
			ld _min = half + dif;
			if (_min < v[i - 1].second)
				_min = v[i - 1].second;
			ret = min(ret, _min);
		}
		else
		{
			if (v[i].first + v[i].second < N)
				continue;
			if (v[i - 1].first - v[i - 1].second > 0)
				continue;
			ld dif = (v[i - 1].second - v[i - 1].first) / 2;
			ld _min = half + dif;
			ld mid = (v[i - 1].first + v[i - 1].second) / 2;
			if (_min < mid)
				_min = mid;
			if (_min < v[i].second)
				_min = v[i].second;
			ret = min(ret, _min);
		}
	}

	if (ret == INF)
		ret = -1;
	return ret;

}

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int T;

	cin >> T;

	for (int test = 1; test <= T; test++)
	{
		cin >> N >> M >> L;

		for (int i = 0; i <= M; i++)
		{
			ll x, y;
			cin >> x >> y;
			v.push_back({ x,y });
		}

		cout << "Case #" << test << "\n";
		
		ld ans = Solve();
		if (ans == -1)
			cout << ans << "\n";
		else
		{
			ll up, down;

			if (ans / 1.00 == (ll)ans)
			{
				up = ans;
				down = 1;
			}
			else
			{
				up = ans * 2;
				down = 2;
			}
			cout << up << " " << down << "\n";
		}
		v.clear();
	}

	return 0;
}