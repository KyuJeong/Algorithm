#include <iostream>

using namespace std;

typedef long long ll;
ll A, B, C;

ll Calc(ll num, ll exp)
{
	if (exp == 0)
		return 1;
	if (exp == 1)
		return num;
	if (exp % 2)
		return num * (Calc(num, exp - 1) % C);
	else
	{
		ll tmp = Calc(num, exp / 2) % C;
		return (tmp * tmp) % C;
	}
}

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> A >> B >> C;

	ll ans = Calc(A, B) % C;

	cout << ans;

	return 0;
}