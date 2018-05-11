#include <bits/stdc++.h>

using namespace std;

int T;

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> T;

	while (T--)
	{
		int M;
		char c;
		cin >> M >> c;
		if (c == 'N')
		{
			for (int i = 0; i < M; i++)
			{
				int tmp;
				cin >> tmp;
				char ch = tmp + 'A' -1;
				cout << ch << " ";
			}
		}
		else
		{
			for (int i = 0; i < M; i++)
			{
				char tmp;
				cin >> tmp;
				cout << tmp - 'A' + 1 << " ";
			}
		}
		cout << "\n";
	}

	return 0;
}