#include <bits/stdc++.h>

using namespace std;

typedef pair <int, int> pii;

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int tc;
	cin >> tc;

	while (tc--)
	{
		int n;
		cin >> n;
		int arr[100001];
		int a, b;
		for (int i = 0; i < n; i++)
		{
			cin >> a >> b;
			arr[a] = b;
		}

		int cnt = 1;
		int minn = arr[1];
		for (int i = 2; i <= n; i++)
		{
			if (minn > arr[i])
			{
				minn = arr[i];
				cnt++;
			}
		}
		cout << cnt << "\n";
	}

	return 0;
}