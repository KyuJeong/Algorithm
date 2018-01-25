#include <iostream>
#include <vector>

using namespace std;

#define MOD 1000

typedef long long ll;
typedef vector <vector <ll>> vvll;
int N;
ll B;
ll G[5][5];
vvll v;

vvll Resize(vvll vl)
{
	vl.resize(N);
	for (int i = 0; i < N; i++)
	{
		vl[i].resize(N);
	}

	return vl;
}

vvll operator * (vvll v1, vvll v2)
{
	vvll v3;
	v3 = Resize(v3);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			ll tmp = 0;
			for (int k = 0; k < N; k++)
			{
				tmp += (v1[i][k] * v2[k][j]);
			}
			v3[i][j] = tmp % MOD;
		}
	}

	return v3;
}

vvll Calc(ll exp, vvll a)
{
	vvll ret;

	if (exp == 1)
		return a;
	if (exp % 2)
	{
		ret = v * Calc(exp - 1, a);
		return ret;
	}
	else
	{
		ret = Calc(exp / 2, a);
		return ret * ret;
	}
}

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> N >> B;

	v.resize(N);

	for (int i = 0; i < N; i++)
	{
		v[i].resize(N);
		for (int j = 0; j < N; j++)
		{
			cin >> v[i][j];
			v[i][j] %= MOD;
		}
	}

	vvll ans = Calc(B, v);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}


	return 0;
}