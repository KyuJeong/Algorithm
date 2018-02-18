#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

ll N, K;
ll arr[100001];
ll minn;
ll typ, cnt;

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> N >> K;

	if (N == 0)
	{
		cout << "1 0";
		return 0;
	}

	typ = 1; cnt = 1;

	minn = 1000000000000000000;

	for (int i = 1; i <= K; i++)
	{
		cin >> arr[i];

		ll mod = N % arr[i];
		if (mod < minn)
		{
			typ = i;
			cnt = N / arr[i];
			minn = mod;
		}
	}

	cout << typ << " " << cnt;


	return 0;
}