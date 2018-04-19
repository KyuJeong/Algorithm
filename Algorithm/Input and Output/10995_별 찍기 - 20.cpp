#include <iostream>

using namespace std;

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int N;

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (i % 2 == 1)
				cout << "* ";
			else
				cout << " *";
		}
		cout << "\n";
	}

	return 0;
}