#include <iostream>

using namespace std;

int n;

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> n;

	if (n <= 5)
	{
		cout << "-1\n";
		for (int i = 2; i <= n; i++)
		{
			cout << "1 " << i << "\n";
		}
	}
	else
	{
		cout << "1 2\n";
		cout << "1 3\n";
		cout << "1 4\n";
		for (int i = 5; i <= n; i++)
		{
			cout << "2 " << i << "\n";
		}

		cout << "1 2\n";
		cout << "1 3\n";
		for (int i = 4; i <= n; i++)
		{
			cout << "2 " << i << "\n";
		}
	}

	return 0;
}