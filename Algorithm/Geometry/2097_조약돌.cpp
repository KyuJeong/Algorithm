#include <bits/stdc++.h>

using namespace std;

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);
	
	int N;
	cin >> N;

	if (N <= 2)
	{
		cout << "4";
		return 0;
	}

	int len = 2;
	int cnt = 2;
	int add = 2;

	while (N > cnt)
	{
		len += 2;
		cnt += add;
		if (N <= cnt)
			break;
		len += 2;
		cnt += add;
		add++;
	}
	
	cout << len;

	return 0;
}