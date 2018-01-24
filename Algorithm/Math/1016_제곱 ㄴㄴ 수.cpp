#include <iostream>
#include <vector>

using namespace std;

#define MAX 1000001

typedef long long ll;

ll maxx, minn;
bool comp[MAX];
vector <ll> prime;
bool comp_pow[MAX];
int ans;

void MakePrime()
{
	for (ll i = 2; i < MAX; i++)
	{
		if (!comp[i])
		{
			for (ll j = i * i; j < MAX; j += i)
			{
				comp[j] = true;
			}
		}
	}

	for (ll i = 2; i * i <= maxx; i++)
	{
		if (!comp[i])
			prime.push_back(i);
	}
}

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> minn >> maxx;
	MakePrime();

	int sze = prime.size();

	for (ll i = 0; i < sze; i++)
	{
		ll add = prime[i] * prime[i];
		
		ll start = minn + add - (minn % add);	// minn부터 maxx까지를 배열의 인덱스로 (오버플로우 방지)
		if (minn % add == 0)
			start = minn;

		if (start - minn < 0)
			cout << "stop";
		
		for (ll j = start; j <= maxx; j += add)
		{
			comp_pow[j - minn] = true;
		}
	}

	for (ll i = minn; i <= maxx; i++)
	{
		if (!comp_pow[i - minn])
			ans++;
	}

	cout << ans;

	return 0;
}