#include <iostream>
#include <algorithm>
using namespace std;

int card[1000];
int N;
int D[1000];

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> card[i];
		D[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (card[j] < card[i] && D[j] >= D[i])
				D[i] = D[j] + 1;
		}
	}

	sort(D, D + N);
	cout << D[N - 1];

	return 0;
}