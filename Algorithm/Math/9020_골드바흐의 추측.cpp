#include <iostream>
#include <vector>

using namespace std;

int T;

bool no_prime[10001];
vector <int> prime;

void MakePrime()
{
	for (int i = 2; i * i <= 10000; i++)
	{
		if (!no_prime[i])
		{
			for (int j = i * i; j <= 10000; j += i)
			{
				no_prime[j] = true;
			}
		}
	}

	for (int i = 2; i <= 10000; i++)
	{
		if (!no_prime[i])
			prime.push_back(i);
	}
}

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	MakePrime();

	cin >> T;

	while (T--)
	{
		int N;
		cin >> N;
		int p1, p2;

		for (int i = 0; prime[i] <= N / 2; i++)
		{
			int cur = prime[i];
			if (!no_prime[N - cur])
			{
				p2 = N - cur;
				p1 = cur;
			}
		}

		cout << p1 << " " << p2 << "\n";
	}

	return 0;
}