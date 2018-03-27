#include <iostream>
#include <algorithm>

using namespace std;

char a[11];

int main()
{
	std::ios::sync_with_stdio(false);

	int idx = 0;

	while (cin >> a[idx])
	{
		idx++;
	}

	sort(a, a + idx);

	for (; idx--; idx >= 0)
	{
		cout << a[idx];
	}

	return 0;
}