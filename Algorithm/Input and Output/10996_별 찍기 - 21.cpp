#include <iostream>

using namespace std;

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int N;

	cin >> N;

	if (N == 1)
	{
		cout << "*";
		return 0;
	}

	for (int i = 1; i <= N * 2; i++)
	{
		if (i % 2 == 1)
		{
			for (int j = 1; j <= (N + 1) / 2; j++)
			{
				cout << "* ";
			}
		}
		else
		{
			for (int j = 1; j <= N / 2; j++)
			{
				cout << " *";
			}
		}
		cout << "\n";
	}

	return 0;
}