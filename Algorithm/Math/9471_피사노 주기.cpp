#include <iostream>

using namespace std;

typedef long long ll;

int T;

int CalcPeriod(int x)
{
	int idx = 1;
	ll pre = 1;
	ll cur = 1;
	ll nxt = 0;
	int mod = x;

	while (1)
	{
		nxt = (cur + pre) % mod;

		if (cur == 1 && nxt == 1)
			return idx;
		idx++;
		pre = cur;
		cur = nxt;
	}
}

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> T;

	while (T--)
	{
		int N, M;
		cin >> N >> M;
		int period = CalcPeriod(M);
		cout << N << " " << period << "\n";
	}

	return 0;
}