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

	if (n == 1 || n == 2)
	{
		cout << "No";
		return 0;
	}

	cout << "Yes\n";
	if (n & 1)
	{
		cout << (n / 2) + 1 << " ";
		for (int i = 1; i <= n; i += 2)
			cout << i << " ";

		cout << "\n";
		cout << (n / 2) << " ";
		for (int i = 2; i <= n; i += 2)
			cout << i << " ";
	}
	else
	{
		cout << n / 2 << " ";
		for (int i = 1; i <= n; i += 2)
			cout << i << " ";

		cout << "\n";
		cout << n / 2 << " ";
		for (int i = 2; i <= n; i += 2)
			cout << i << " ";
	}

	return 0;
}