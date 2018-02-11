#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

ll n, k;
vector <int> v;

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> n >> k;

	for (ll i = 1; i <= k; i++)
	{
		ll tmp = n % i;
		for (auto j : v)
		{
			if (tmp == j)
			{
				cout << "No";
				return 0;
			}
		}
		v.push_back(tmp);
	}

	cout << "Yes";

	return 0;
}