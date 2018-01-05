#include <iostream>

using namespace std;

long long int cur[10];
long long int nxt[10];
long long int cur_sum;
long long int nxt_sum;

int main()
{
	std::ios::sync_with_stdio(false);

	int N;

	cin >> N;
	cur_sum = 1;

	for (int i = 0; i < N; i++)
	{
		nxt[0] = cur_sum;
		for (int j = 1; j < 10; j++)
		{
			nxt[j] = (nxt[j - 1] - cur[j - 1]);
		}

		for (int j = 0; j < 10; j++)
		{
			nxt[j] %= 10007;
			cur[j] = nxt[j];
			nxt_sum += nxt[j];
		}

		cur_sum = nxt_sum;
		nxt_sum = 0;
	}

	cout << cur_sum % 10007;

	return 0;
}