#include <iostream>
using namespace std;

int main()
{
	int N;
	long long K;
	int value[10] = { 0, };
	int coin_num = 0;
	cin >> N >> K;

	for (int i = 0; i < N; i++)
	{
		cin >> value[i];
	}

	for (int i = N - 1; i >= 0; i--)
	{
		if (value[i] <= K)
		{
			coin_num += (K / value[i]);
			K %= value[i];
			if (K % value[i] == 0)
				break;
			i = N;
		}

	}

	cout << coin_num;

	return 0;
}