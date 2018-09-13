#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

int n;
vector <ll> A;
ll sum;

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> n;
	A.resize(n);

	for (int i = 0; i < n; i++)
		cin >> A[i];

	if (n == 1)
	{
		cout << A[0];
		return 0;
	}

	bool plus = false;
	bool minus = false;

	ll _max = -1e10;
	ll _min = 1e10;

	for (auto i : A)
	{
		if (i < 0)
		{
			minus = true;
			_max = max(_max, i);
		}
		else
		{
			plus = true;
			_min = min(_min, i);
		}
	}

	if (minus && plus)
	{
		for (auto i : A)
			sum += abs(i);
	}
	else if (minus)
	{
		sum = _max * 2;
		for (auto i : A)
			sum += abs(i);
	}
	else
	{
		sum = -_min * 2;
		for (auto i : A)
			sum += i;
	}

	cout << sum;

	return 0;
}