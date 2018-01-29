#include <iostream>
#include <string>
#include <string.h>

#define MOD 100000

using namespace std;

int N;
string s;
char open = '(';
char close = ')';
int DP[201][201];	// i~j까지 만들 수 있는 올바른 문자열의 최대값
bool modular;

long long Solve(int i, int j)
{
	if (i >= j)
		return 1;

	int &ret = DP[i][j];

	if (ret != -1)
		return ret;

	ret = 0;


	for (int k = i + 1; k <= j; k++)
	{
		if (s[i] == open || s[i] == '?')
		{
			if (s[k] == close || s[k] == '?')
			{
				if (Solve(i + 1, k - 1) && Solve(k + 1, j))
					ret = 1;
			}
		}
	}

	return ret;
}

int main()
{
	std::ios::sync_with_stdio(false);

	memset(DP, -1, sizeof(DP));

	cin >> s;
	N = s.size();

	int ans = Solve(0, N - 2);
	ans = Solve(1, N - 1);

	cout << ans;

	return 0;
}