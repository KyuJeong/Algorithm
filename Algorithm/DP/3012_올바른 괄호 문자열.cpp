#include <iostream>
#include <string>
#include <string.h>

#define MOD 100000

using namespace std;

int N;
string s;
string open = "({[";
string close = ")}]";
long long DP[201][201];	// i~j까지 만들 수 있는 올바른 문자열의 최대값
bool modular;

long long Solve(int src, int dsc)
{
	if (src > dsc)
		return 1;

	long long &ret = DP[src][dsc];
	
	if (ret != -1)
		return ret;

	ret = 0;

	for (int k = src + 1; k <= dsc; k += 2)
	{
		for (int l = 0; l < 3; l++)
		{
			if (s[src] == open[l] || s[src] == '?')
			{
				if (s[k] == close[l] || s[k] == '?')
				{
					long long tmp = Solve(src + 1, k - 1) * Solve(k + 1, dsc);
					ret += tmp;
					if (ret >= MOD)
						modular = true;
					ret %= MOD;
				}
			}
		}
	}

	return ret;
}

int main()
{
	std::ios::sync_with_stdio(false);

	memset(DP, -1, sizeof(DP));

	cin >> N;
	cin >> s;

	if (N % 2 == 1)
	{
		printf("0\n");
		return 0;
	}

	long long ans = Solve(0, N - 1);

	if (modular)
		printf("%05lld\n", ans);
	else
		printf("%lld\n", ans);

	return 0;
}