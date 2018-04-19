#include <iostream>

using namespace std;

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int N;

	while (1)
	{
		cin >> N;
		if (N == 0)
			break;

		int pre = -1;
		int cur;
		for (int i = 0; i < N; i++)
		{
			cin >> cur;
			if (cur != pre)
				cout << cur <<" ";
			pre = cur;
		}
		cout << "$\n";
	}
	return 0;
}