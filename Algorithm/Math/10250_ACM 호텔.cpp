#include <iostream>

using namespace std;

int T;

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> T;

	while (T--)
	{
		int H, W, N;

		cin >> H >> W >> N;

		cout << (N - 1) % H + 1;
		if (((N - 1) / H + 1) < 10)
			cout << "0";
		cout << (N - 1) / H + 1 << "\n";
	}

	return 0;
}