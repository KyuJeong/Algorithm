#include <iostream>
using namespace std;

int N;
int NFac;

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> N;

	for (int i = 5; i <= N; i += 5)
	{
		NFac++;
	}

	for (int i = 25; i <= N; i += 25)
	{
		NFac++;
	}

	for (int i = 125; i <= N; i += 125)
	{
		NFac++;
	}

	cout << NFac;

	return 0;
}