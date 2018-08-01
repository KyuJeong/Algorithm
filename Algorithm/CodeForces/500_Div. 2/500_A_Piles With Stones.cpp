#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int n;
	cin >> n;
	int s = 0;
	int r = 0;

	int tmp;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		s += tmp;

	}
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		r += tmp;
	}

	if (s >= r)
		cout << "Yes";
	else
		cout << "No";

	return 0;
}