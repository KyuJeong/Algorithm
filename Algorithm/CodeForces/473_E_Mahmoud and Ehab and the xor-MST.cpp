#include <iostream>
#include <cmath>

using namespace std;

#define MAX 1000000000000

typedef long long ll;

ll N;
ll two[41];
ll three[41];
ll ans;

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> N;

	two[1] = 1;
	for (int i = 2; i < 41; i++)
	{
		two[i] = two[i - 1] * 2 + pow(2, i - 1);
	}
	for (int i = 1; i < 40; i++)
	{
		three[i] = two[i + 1] - two[i];
	}

	int start;

	for (int i = 1; i < 40; i++)
	{
		if (three[i] < N)
			start = i;
	}

	ll idx = start;
	ll nxt;

	while (idx > 1)
	{
		ans += three[idx];
		ll mod = pow(2, idx);
		N %= mod;
		idx--;

		//N % 2 
	}

	cout << ans;

	return 0;
}