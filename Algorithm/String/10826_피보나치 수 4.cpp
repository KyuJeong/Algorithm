#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int N;
string DP[10001];

inline string Calc(string a, string b)
{
	string ret = "";

	int a_size = a.size();
	int b_size = b.size();
	int j = 0;

	for (int i = 0; i < b_size; i++)
	{
		if (j < a_size)
			ret += a[j] + b[i] - '0';
		else
			ret += b[i];
		j++;
	}

	for (int i = 0; i < b_size; i++)
	{
		if (ret[i] > '9')
		{
			ret[i] -= 10;
			if (i == b_size - 1)
				ret += '1';
			else
				ret[i + 1]++;
		}
	}

	return ret;
}

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> N;

	DP[0] = "0";
	DP[1] = "1";

	for (int i = 2; i <= N; i++)
	{
		DP[i] = Calc(DP[i - 2], DP[i - 1]);
	}

	reverse(DP[N].begin(), DP[N].end());

	cout << DP[N];

	return 0;
}